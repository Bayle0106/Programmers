//
//  DiaryViewController.swift
//  PlanningApp
//
//  Created by 이태곤 on 2022/09/13.
//

import UIKit
import RealmSwift

class DiaryViewController: UIViewController, UICollectionViewDelegate {
    @IBOutlet weak var diaryCollectionView: UICollectionView!
    @IBOutlet weak var naviBar: UINavigationBar!
    
    var level: Int = 4
    var parentLabel: String = ""
    var viewModel: PlanViewModel!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        diaryCollectionView.delegate = self
        diaryCollectionView.dataSource = self
        
        let realm = try! Realm()
        viewModel = PlanViewModel(realm: realm)
        
        naviBar.titleTextAttributes = [.foregroundColor: UIColor.white]
        
        // Do any additional setup after loading the view.
    }
    
    
    
    @IBAction func backButtonPressed(_ sender: Any) {
        let transition = viewModel.changeView(pushType: "Left")
        view.window!.layer.add(transition, forKey: kCATransition)
        dismiss(animated: false)
    }
    
    
    @IBAction func newButtonPressed(_ sender: Any) {
        let sb = UIStoryboard(name: "AddPlanView", bundle: nil)
        let vc = sb.instantiateViewController(withIdentifier: "AddPlanViewController") as! AddPlanViewController
        vc.modalPresentationStyle = .fullScreen
        vc.parentPlan = parentLabel
        vc.collectionView = diaryCollectionView
        
        
        let transition = viewModel.changeView(pushType: "Right")
        view.window!.layer.add(transition, forKey: kCATransition)
        present(vc, animated: false)
        
    }
}

extension DiaryViewController: UICollectionViewDataSource {
    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        let tmp = viewModel.findPlan(level: 4, parentPlan: parentLabel)
        return tmp.count
    }

    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        guard let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "DiaryViewCell", for: indexPath) as? DiaryViewCell else {
            return UICollectionViewCell()
        }


        let resultCell = viewModel.viewDiaryList(cell: cell, index: indexPath.row, parent: parentLabel)
        return resultCell
    }
}

extension DiaryViewController: UICollectionViewDelegateFlowLayout {
    func collectionView(_ collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, sizeForItemAt indexPath: IndexPath) -> CGSize {
        let interspacing: CGFloat = 20
        let width: CGFloat = (collectionView.bounds.width - interspacing) / 2
        let height = width
        return CGSize(width: width, height: height)
    }
}
