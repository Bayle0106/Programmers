//
//  PopupViewController.swift
//  PlanningApp
//
//  Created by 이태곤 on 2022/08/31.
//

import UIKit
import RealmSwift

class PopupViewController: UIViewController {
    @IBOutlet weak var PopupLabel: UITextField!
    @IBOutlet weak var popUpView: UIView!
    
    var position: Int = 0
    var level: Int = 1
    var parentPlan: String = ""
    var collectionView: UICollectionView?
    var tableView: UITableView?
    var viewModel: PlanViewModel!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        popUpView.layer.cornerRadius = 10
        
        let realm = try! Realm()
        viewModel = PlanViewModel(realm: realm)
    }
    
    @IBAction func saveButtonPressed(_ sender: Any) {
        if PopupLabel.text != "" { viewModel.addPlan(plan: PopupLabel.text!, pos: position, level: level, parent: parentPlan) }
        dismiss(animated: true, completion: {
            self.collectionView?.reloadData()
            self.tableView?.reloadData()
        })
    }
    
    @IBAction func cancleButtonPressed(_ sender: Any) {
        dismiss(animated: true)
    }
    
}
