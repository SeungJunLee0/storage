from __future__ import division
from __future__ import print_function

import sys
import argparse
import ROOT
from ROOT import TLegend
if sys.version_info.major == 2:
    from pathlib2 import Path
elif sys.version_info[:2] >= (3, 4):
    from pathlib import Path
else:
    raise ImportError

def draw_compare(me, filesys_dir, compareme):
    print("start: {},  ".format(me), end="")
    name = me.GetName()
    print(name)

    canvas_name = 'canvas_' + name
    if 'occ_det' in name:
        canvas = ROOT.TCanvas(canvas_name, canvas_name, 1200, 800)
    else:
        canvas = ROOT.TCanvas(canvas_name, canvas_name, 600, 400)
    canvas.cd()

    me_class_name = me.ClassName()
    compareme_class_name = compareme.ClassName()
    print('me_class_name done')
    if me_class_name == 'TH1F':
        me.SetLineColor(ROOT.kBlue)
        me.SetLineWidth(2)
        me.SetLineStyle(2)
        compareme.SetLineColor(ROOT.kRed)
        compareme.SetLineWidth(2)
        compareme.SetLineStyle(10)
        scale_me = me.GetMaximum()
        scale_compare = compareme.GetMaximum()
        if scale_me > scale_compare:
            me.SetMaximum(scale_me*1.2) 
        else:
            me.SetMaximum(scale_compare*1.2)
        me.Draw('sames hist')
        compareme.Draw('sames hist')


        leg = ROOT.TLegend(0.6,0.7,0.9,0.9)
        leg.SetTextSize(0.03)
        #leg.SetHeader("blue = New Topology","C")
        leg.AddEntry(me," New Topology","L")
        leg.AddEntry(compareme," Old Topology" ,"L")
        leg.Draw()
        print('me.Draw done')
    #    if 'residual_x' in name:
    #        f = me.GetFunction('gaus')
    #        fcompare = compareme.GetFunction('gaus')
    #        print('GetFunction done')
    #        f.Draw('same')
    #        fcompare.Draw('same')
	#		### what is it?????
    #        print('f Draw done')
    elif me_class_name == 'TProfile':
        me.SetLineColor(ROOT.kBlue)
        me.SetLineWidth(2)
        me.SetStats(0)
        me.Draw()
        compareme.SetLineColor(ROOT.kRed)
        compareme.SetLineWidth(2)
        compareme.SetStats(0)
        compareme.Draw('same')
    elif me_class_name == 'TH2F':
        if 'polar' in name:
            max_r = me.GetYaxis().GetXmax()
            canvas.DrawFrame(-max_r, -max_r, max_r, max_r)
            me.DrawCopy('same colz pol')
            latex = ROOT.TLatex()
            latex.DrawLatexNDC(0.15, 0.92, me.GetTitle())
        elif 'occ_det' in name:
            canvas.SetBottomMargin(0.2)
            me.GetXaxis().SetTitleOffset(3)
            me.GetXaxis().LabelsOption('v')
            me.GetYaxis().SetTitleOffset(0.4)
            me.Draw('colz')
			###what isit???? i think this cannt draw same plot
        else:
	        me.Draw('colz')
    else:
        raise TypeError

    path = str(filesys_dir.joinpath(name + '.png'))
    canvas.SaveAs(path)

    print("END {}".format(name))
    return None

'''
def draw(me, filesys_dir):
    print("start: {},  ".format(me), end="")
    name = me.GetName()
    print(name)

    canvas_name = 'canvas_' + name
    if 'occ_det' in name:
        canvas = ROOT.TCanvas(canvas_name, canvas_name, 1200, 800)
    else:
        canvas = ROOT.TCanvas(canvas_name, canvas_name, 600, 400)
    canvas.cd()

    f = None
    me_class_name = me.ClassName()
    print('me_class_name done')
    if me_class_name == 'TH1F':
        me.SetLineColor(ROOT.kBlue)
        me.SetLineWidth(2)
        me.Draw('HIST')
        print('me.Draw done')
        if 'residual_x' in name:
            f = me.GetFunction('gaus')
            print('GetFunction done')
            f.Draw('same')
            print('f Draw done')
    elif me_class_name == 'TProfile':
        me.SetLineColor(ROOT.kRed)
        me.SetLineWidth(2)
        me.SetStats(0)
        me.Draw()
    elif me_class_name == 'TH2F':
        if 'polar' in name:
            max_r = me.GetYaxis().GetXmax()
            canvas.DrawFrame(-max_r, -max_r, max_r, max_r)
            me.DrawCopy('same colz pol')
            latex = ROOT.TLatex()
            latex.DrawLatexNDC(0.15, 0.92, me.GetTitle())
        elif 'occ_det' in name:
            canvas.SetBottomMargin(0.2)
            me.GetXaxis().SetTitleOffset(3)
            me.GetXaxis().LabelsOption('v')
            me.GetYaxis().SetTitleOffset(0.4)
            me.Draw('colz')
        else:
	        me.Draw('colz')
    else:
        raise TypeError

    path = str(filesys_dir.joinpath(name + '.png'))
    canvas.SaveAs(path)

    print("END {}".format(name))
    return None



def draw_all_before(root_dir, filesys_dir):
    filesys_dir.mkdir()
    for key in root_dir.GetListOfKeys():
        obj = root_dir.Get(key.GetName())
        class_name = key.GetClassName()

        if isinstance(obj, ROOT.TDirectoryFile):
            subdir = filesys_dir.joinpath(obj.GetName())
            draw_all_before(obj, subdir)
        else:
            draw(obj, filesys_dir)
'''


def draw_all(root_dir, filesys_dir, root_dir_compare):
    filesys_dir.mkdir()
    for key in root_dir.GetListOfKeys():
        obj = root_dir.Get(key.GetName())
        class_name = key.GetClassName()

        if isinstance(obj, ROOT.TDirectoryFile):
            subdir = filesys_dir.joinpath(obj.GetName())
            for key_compare in root_dir_compare.GetListOfKeys():
                print("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
                print(key)
                print("upup")	
                print(key_compare)
                print("down")
                keyname1 = key.GetName()
                keyname2 = key_compare.GetName()
                if keyname1 == keyname2:
                    obj_compare = root_dir_compare.Get(key_compare.GetName())
                    class_name_compare = key_compare.GetClassName()
                    draw_all(obj, subdir, obj_compare)
        else:
            
            for key_compare in root_dir_compare.GetListOfKeys():
                keyname11 = key.GetName()
                keyname22 = key_compare.GetName()

                if keyname11 == keyname22:
                    obj_compare = root_dir_compare.Get(key_compare.GetName())
                    class_name_compare = key_compare.GetClassName()
                    draw_compare(obj, filesys_dir, obj_compare)

'''        if isinstance(obj, ROOT.TDirectoryFile):
            subdir = filesys_dir.joinpath(obj.GetName())
            draw_all_before(obj, subdir)
        else:
            draw(obj, filesys_dir)

   '''     
def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('-i', '--in-path', type=str, default='DQM_V0001_R000000001__Global__CMSSW_X_Y_Z__RECO.root')
	#stand!!!! new topology
    parser.add_argument('-i2', '--in-compare', type=str, default='/cms/ldap_home/seungjun/what2/ol/CMSSW_11_2_X_2020-10-05-1200/src/23434.999_TTbar_14TeV+2026D49PU_PMXS1S2PR+TTbar_14TeV_TuneCP5_GenSimHLBeamSpot14+PREMIX_PremixHLBeamSpot14PU+DigiTriggerPU+RecoGlobalPU+HARVESTGlobalPU/DQM_V0001_R000000001__Global__CMSSW_X_Y_Z__RECO.root')
    #parser.add_argument('-i2', '--in-compare', type=str, default='DQM_V0001_R000000001__Global__CMSSW_X_Y_Z__RECO_origin.root')
    #compare  old topology
    parser.add_argument('-o', '--out-dir', type=str, default='./DQM_1101_1110')
    args = parser.parse_args()

    root_file = ROOT.TFile(args.in_path)
    root_file_compare = ROOT.TFile(args.in_compare)
    root_dir = root_file.Get('DQMData/Run 1')
    root_dir_compare = root_file_compare.Get('DQMData/Run 1')
    filesys_dir = Path(args.out_dir)
    if filesys_dir.exists():
        raise IOError("Cannot create directory '{}': File exits!!!".format(args.out_dir))
    filesys_dir.mkdir()

    draw_all(root_dir.Get('MuonGEMHitsV/Run summary/GEMHitsTask'),
        filesys_dir.joinpath('MuonGEMHits'),
        root_dir_compare.Get('MuonGEMHitsV/Run summary/GEMHitsTask'))

    draw_all(root_dir.Get('MuonGEMDigisV/Run summary/GEMDigisTask'),
        filesys_dir.joinpath('MuonGEMDigis'),
        root_dir_compare.Get('MuonGEMDigisV/Run summary/GEMDigisTask'))

    draw_all(root_dir.Get('MuonGEMRecHitsV/Run summary/GEMRecHitsTask'),
        filesys_dir.joinpath('MuonGEMRecHits'),
        root_dir_compare.Get('MuonGEMRecHitsV/Run summary/GEMRecHitsTask'))

if __name__ == '__main__':
    ROOT.gROOT.SetBatch(True)
    main()
