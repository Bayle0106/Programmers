//
//  FirstLevelViewController.swift
//  PlanningApp
//
//  Created by 이태곤 on 2022/08/31.
//

import UIKit
import RealmSwift

class FirstLevelViewController: UIViewController {
    let level: Int = 1
    let parentPlan: String = ""
    
    var viewModel: PlanViewModel!
    @IBOutlet weak var newButton: UIButton!
    @IBOutlet weak var tableView: UITableView!
    
    override func viewDidLoad() {
        super.viewDidLoad()

        //deleteRealm()
        let realm = try! Realm()
        print(Realm.Configuration.defaultConfiguration.fileURL!)
        viewModel = PlanViewModel(realm: realm)
        
        tableView.delegate = self
        tableView.dataSource = self
        
//        saveBarView.layer.cornerRadius = 40
//        saveBarView.layer.maskedCorners = [.layerMinXMinYCorner, .layerMaxXMinYCorner]
        
//        newButton.setImage(UIImage(systemName: "plus"), for: .normal)
//        newButton.tintColor = UIColor.systemIndigo
//        newButton.bounds = CGRect(x: 0, y: 0, width: 20, height: 20)
    
        
    }
    
    @IBAction func newButtonPressed(_ sender: Any) {
        let sb = UIStoryboard(name: "Popup", bundle: nil)
        let vc = sb.instantiateViewController(withIdentifier: "PopupViewController") as! PopupViewController
        vc.modalPresentationStyle = .overCurrentContext
        vc.tableView = tableView
        present(vc, animated: false)
    }
}

extension FirstLevelViewController: UITableViewDataSource {
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        guard let cell = tableView.dequeueReusableCell(withIdentifier: "FirstLevelTableViewCell", for: indexPath) as? FirstLevelTableViewCell else {
            return UITableViewCell()
        }
        let resultCell = viewModel.viewMainPlan(cell: cell, index: indexPath.row, parent: parentPlan)
        return resultCell
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        let tmp = viewModel.findPlan(level: level, parentPlan: parentPlan)
        return tmp.count
    }
    
    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        return 100
    }
}

extension FirstLevelViewController: UITableViewDelegate {
    func tableView(_ tableView: UITableView, trailingSwipeActionsConfigurationForRowAt indexPath: IndexPath) -> UISwipeActionsConfiguration? {
        let delete = UIContextualAction(style: .normal, title: "삭제") { (UIContextualAction, UIView, success: @escaping (Bool) -> Void) in
            //print("삭제 클릭 됨")
            
            let alert = UIAlertController(title: "Plan을 삭제 하시겠습니까?", message: "모든 하위 항목이 제거됩니다.", preferredStyle: UIAlertController.Style.alert)
            let cancle = UIAlertAction(title: "취소", style: .default, handler: nil)
            let okay = UIAlertAction(title: "확인", style: .destructive, handler: { [self]
                plan in
                let tmp = viewModel.findPlan(level: level, parentPlan: parentPlan)
                viewModel.deletePlan(deletePlan: tmp[indexPath.row].plan)
                self.tableView?.reloadData()
            })
            alert.addAction(cancle)
            alert.addAction(okay)
            self.present(alert, animated: true, completion: nil)
            
            success(true)
        }
        delete.backgroundColor = .systemRed
        
        //actions배열 인덱스 0이 오른쪽에 붙어서 나옴
        return UISwipeActionsConfiguration(actions:[delete])
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        let tmp = viewModel.findPlan(level: level, parentPlan: parentPlan)
        
        let sb = UIStoryboard(name: "Main", bundle: nil)
        
        guard let vc = sb.instantiateViewController(withIdentifier: "PlanViewController") as? PlanViewController else { return }
        vc.modalPresentationStyle = .fullScreen
        
        vc.parentPlan = tmp[indexPath.row].plan
        vc.level = 2
        
        let transition = viewModel.changeView(pushType: "Right")
        view.window!.layer.add(transition, forKey: kCATransition)
        present(vc, animated: false)
    }
}



// Realm의 구조를 변경하거나 꼬였을때 realm파일 자체를 제거하는 코드 -> 필요할때만 쓰자: ViewDidLoad에 있음.
func deleteRealm(){
    let realmURL = Realm.Configuration.defaultConfiguration.fileURL!
    let realmURLs = [realmURL,
                     realmURL.appendingPathExtension("lock"),
                     realmURL.appendingPathExtension("note"),
                     realmURL.appendingPathExtension("management")
    ]
    for URL in realmURLs {
        do {
            try FileManager.default.removeItem(at: URL)
            
        } catch {
            
        }
        
    }
}
