//
//  AddPlanViewController.swift
//  PlanningApp
//
//  Created by 이태곤 on 2022/08/28.
//

import UIKit
import RealmSwift

class AddPlanViewController: UIViewController {
    
    @IBOutlet weak var titleTextField: UITextField!
    @IBOutlet weak var dateLabel: UILabel!
    @IBOutlet weak var contentTextField: UITextField!
    
    var date: Date? = nil
    
    var viewModel: PlanViewModel! = nil
    var collectionView: UICollectionView?
    var parentPlan: String = ""
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        let realm = try! Realm()
        viewModel = PlanViewModel(realm: realm)
        
        date = Date()
        let formatter = DateFormatter()
        formatter.dateFormat = "yyyy년 MM월 dd일"
        dateLabel.text = formatter.string(from: date!)

    }

    // 확인차 plan만 추가가 되게 설정
    // 최하위 생성
    
    @IBAction func saveButtonPressed(_ sender: Any) {
        let content: String = contentTextField.text!
        let title: String = titleTextField.text!
        
        let formatter = DateFormatter()
        formatter.dateFormat = "MM-DD-yyyy HH:mm"
        let dateForObj = formatter.string(from: date!)
        
        if title != "" {
            viewModel.addDiary(title: title, date: dateForObj, content: content, level: 4, parentPlan: parentPlan)
            let transition = viewModel.changeView(pushType: "Left")
            view.window!.layer.add(transition, forKey: kCATransition)
            dismiss(animated: false, completion: {
                self.collectionView?.reloadData()
            })
        }
    }
    
    
    @IBAction func cancleButtonPressed(_ sender: Any) {
        let transition = viewModel.changeView(pushType: "Left")
        view.window!.layer.add(transition, forKey: kCATransition)
        dismiss(animated: false)
    }
    
    
}

