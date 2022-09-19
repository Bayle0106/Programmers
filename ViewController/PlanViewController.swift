//
//  PlanViewController.swift
//  PlanningApp
//
//  Created by 이태곤 on 2022/08/23.
//

import UIKit
import RealmSwift
import Foundation
import SwiftUI

class PlanViewController: UIViewController {
    
    //var modelList: [TestModel] = TestModel.list
    var currentLongPressedCell: PlanCollectionViewCell?
    var viewModel: PlanViewModel!
    var parentPlan: String = ""
    var level: Int = 2
    
    @IBOutlet weak var planLabel: UILabel!
    @IBOutlet weak var TopBarView: UIView!
    @IBOutlet weak var MainView: UIView!
    @IBOutlet weak var collectionView: UICollectionView!
    
    // realm 파일 꼬이면 실행
    
    
    // Realm 초기화
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        let planRealm = try! Realm()
        viewModel = PlanViewModel(realm: planRealm)
        
        TopBarView.layer.cornerRadius = 40
        TopBarView.layer.maskedCorners = [.layerMinXMaxYCorner, .layerMaxXMaxYCorner]
        
        MainView.layer.cornerRadius = 40
        
        planLabel.text = parentPlan
        
        collectionView.dataSource = self
        collectionView.delegate = self
        
        setupLongGestureRecognizerOnCollection()
    }
    
    
    @IBAction func backButtonPressed(_ sender: Any) {
        let transition = viewModel.changeView(pushType: "Left")
        view.window!.layer.add(transition, forKey: kCATransition)
        dismiss(animated: false)
    }
    
    
}

extension PlanViewController: UICollectionViewDataSource {
    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return 9
    }
    
    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        guard let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "PlanCollectionViewCell", for: indexPath) as? PlanCollectionViewCell else {
            return UICollectionViewCell()
        }
        let resultcell = viewModel.viewSubPlans(cell: cell, index: indexPath.row, parent: parentPlan)
        //collectionView.reloadData()
        
        //print("called cell")// 여기는 한번 호출되고 만다.
        return resultcell
    }
}

extension PlanViewController: UICollectionViewDelegateFlowLayout {
    func collectionView(_ collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, sizeForItemAt indexPath: IndexPath) -> CGSize {
        
        let interItemSpacing: CGFloat = 10
        
        let width = (collectionView.bounds.width - interItemSpacing * 2) / 3
        let height = (collectionView.bounds.height - interItemSpacing * 2) / 3
        return CGSize(width: width, height: height)
    }
}

extension PlanViewController: UICollectionViewDelegate {
    func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath) {
        
        // 해당 indexPath의 PK를 토대로 Realm에서 검색을 하고 새로 띄움. 단계는 +1
        // 단계는 전역변수로 관리해야될듯?
        
        // 클릭시 present 넘어가는 조건 달기
        // 1. 생성 페이지 -> 값이 없는 경우 -> 여기서 Realm에 값을 넣고 Update하는 부분이 존재.
        // 2. 조회 페이지 -> 있는 경우 -> 여기서 Realm의 filter와 sort기능을 이용하여 조회하고
        // 화면에 나타내는 기능을 함.
        
        // 여기서 클릭이 되면 뷰모델로 해당 cell의 String 을 넘겨서 이후 수행은 맡기자ㅇㅇ
        // 이렇게 해서 받은 output 값을 이용하여 판단.
        
        // 선택된 cell에서 정보 얻어내기
        let selectedItem = collectionView.cellForItem(at: indexPath) as? PlanCollectionViewCell
        let exercise: String = selectedItem?.subPlanLabel.text ?? ""
        print("목표: \(exercise)")
        
        // level3 항목 생성: Popup사용
        if exercise == "" && (level == 2 || level == 3) {
            let sb = UIStoryboard(name: "Popup", bundle: nil)
            let vc = sb.instantiateViewController(withIdentifier: "PopupViewController") as! PopupViewController
            vc.parentPlan = parentPlan
            vc.position = indexPath.row
            vc.collectionView = collectionView//collectionView 전달.
            vc.level = level
            vc.modalPresentationStyle = .overCurrentContext
            present(vc, animated: false)
        }
        // level3의 하위 뷰 표시
        else if exercise != "" && level == 2 {
            let sb = UIStoryboard(name: "Main", bundle: nil)
            let vc = sb.instantiateViewController(withIdentifier: "PlanViewController") as! PlanViewController //collectionView 전달.
            vc.level = 3
            vc.parentPlan = exercise
            vc.modalPresentationStyle = .fullScreen
            let transition = viewModel.changeView(pushType: "Right")
            view.window!.layer.add(transition, forKey: kCATransition)
            present(vc, animated: false)
        }
        
        else if exercise != "" && level == 3 {
            let sb = UIStoryboard(name: "Diary", bundle: nil)
            let vc = sb.instantiateViewController(withIdentifier: "DiaryViewController") as! DiaryViewController
            vc.modalPresentationStyle = .fullScreen
            vc.parentLabel = exercise
            let transition = viewModel.changeView(pushType: "Right")
            view.window!.layer.add(transition, forKey: kCATransition)
            present(vc, animated: false)
            
        }
    }
}

extension PlanViewController: UIGestureRecognizerDelegate {
    private func setupLongGestureRecognizerOnCollection() {
        let longPressedGesture = UILongPressGestureRecognizer(target: self, action: #selector(handleLongPress(gestureRecognizer:)))
        longPressedGesture.minimumPressDuration = 0.4
        longPressedGesture.delegate = self
        longPressedGesture.delaysTouchesBegan = true
        collectionView.addGestureRecognizer(longPressedGesture)
    }
    
    // LongPress에 대한 메소드
    @objc func handleLongPress(gestureRecognizer: UILongPressGestureRecognizer) {
            
        let location = gestureRecognizer.location(in: gestureRecognizer.view)
        let collectionView = gestureRecognizer.view as! UICollectionView
        
        if gestureRecognizer.state == .began {
            if let indexPath = collectionView.indexPathForItem(at: location) {
                print("Long touch!: \(indexPath.row)")
                
                // animation
                UIView.animate(withDuration: 0.2) {
                    if let cell = collectionView.cellForItem(at: indexPath) as? PlanCollectionViewCell {
                        self.currentLongPressedCell = cell
                        cell.transform = .init(scaleX: 0.95, y: 0.95)
                    }
                }
                
            }
            
        } else if gestureRecognizer.state == .ended {
            if let indexPath = collectionView.indexPathForItem(at: location) {
                print("Long touch ended!!: \(indexPath.row)")
                
                UIView.animate(withDuration: 0.2) {
                    if let cell = self.currentLongPressedCell {
                        cell.transform = .init(scaleX: 1, y: 1)
                        
                        if cell == collectionView.cellForItem(at: indexPath) as? PlanCollectionViewCell {
                            let alert = UIAlertController(title: "Plan을 삭제 하시겠습니까?", message: "모든 하위 항목이 제거됩니다.", preferredStyle: UIAlertController.Style.alert)
                            let cancle = UIAlertAction(title: "취소", style: .default, handler: nil)
                            let okay = UIAlertAction(title: "확인", style: .destructive, handler: {
                                plan in
                                let selectedItem = collectionView.cellForItem(at: indexPath) as? PlanCollectionViewCell
                                self.viewModel.deletePlan(deletePlan: selectedItem?.subPlanLabel.text ?? "")
                                self.collectionView?.reloadData()
                            })
                            alert.addAction(cancle)
                            alert.addAction(okay)
                            self.present(alert, animated: true, completion: nil)
                        }
                    }
                }
            }
        } else {
            return
        }
    }
}
