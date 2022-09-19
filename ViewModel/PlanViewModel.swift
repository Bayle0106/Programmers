//
//  MainViewModel.swift
//  PlanningApp
//
//  Created by 이태곤 on 2022/08/23.
//

import Foundation
import RealmSwift

let colors: [UIColor] = [.cyan, .orange, .green, .yellow]

// 여기엔 DB의 정보를 가져와서 VC에서 입력된 정보를 토대로
// DB를 최신화하고 그에 맞는 결과를 뱉어주는 것이다.
final class PlanViewModel {
    
    // 여기서 VC에서 넘긴 subPlan을 받아 내용을 처리해준다.
    let realm: Realm
    
    init(realm: Realm) {
        self.realm = realm
    }
    
    
    
    func changeView(pushType: String) -> CATransition {
        let transition = CATransition()
        transition.duration = 0.2
        transition.type = CATransitionType.push
        if pushType == "Left" { transition.subtype = CATransitionSubtype.fromLeft }
        else if pushType == "Right" { transition.subtype = CATransitionSubtype.fromRight }
        transition.timingFunction = CAMediaTimingFunction(name: CAMediaTimingFunctionName.easeInEaseOut)
        return transition
    }
    
    // FirstLevel
    func findPlan(level: Int, parentPlan: String) -> Results<PlanObj> {
        let count = realm.objects(PlanObj.self).where {
            $0.level == level &&
            $0.parentPlan == parentPlan
        }
        return count
    }
    
    func viewMainPlan(cell: FirstLevelTableViewCell, index: Int, parent: String) -> FirstLevelTableViewCell {
        //let filteredPlan = realm.objects(PlanObj.self).filter("parentPlan == \(parent)")
        let filteredPlan = findPlan(level: 1, parentPlan: parent)
        let plan = filteredPlan[index]
        cell.configure(plan: plan, index: index)
        //cell.backgroundColor = colors[index % 4]
        return cell
    }

    func viewDiaryList(cell: DiaryViewCell, index: Int, parent: String) -> DiaryViewCell {
        let filteredPlan = findPlan(level: 4, parentPlan: parent)
        let plan = filteredPlan[index]
        cell.configure(plan: plan, date: plan.plan)
        return cell
    }
    
    // SecondLevel
    
    func checkBeforeAdd(plan: String) -> Bool {
        let tmp = realm.objects(PlanObj.self).where { $0.plan == plan }
        var result: Bool = true
        
        print("num: \(tmp.count)")
        if tmp.count > 0 { result = false }
        return result
         
    }
    
    // 1. plan이 있음 -> 표시창으로 넘어가기
    // 2. plan이 없음 -> 생성창으로 넘어감.
    
    // 빈 칸에 새로운 목표 삽입
    // 일단은 확인만 하게 plan만 추가되게
    func addPlan (plan: String, pos: Int?, level: Int, parent: String?){
        if checkBeforeAdd(plan: plan) {
            let newPlan = PlanObj(plan: plan)
            newPlan.position = pos
            newPlan.parentPlan = parent
            newPlan.level = level
            //newPlan.plan = plan
            
            try! realm.write {
                realm.add(newPlan, update: .modified)
            }
        }
       
    }
    
    //  단일성 확보를 위해 시간을 PK로 설정
    func addDiary(title: String, date: String, content: String, level: Int, parentPlan: String) {
        if checkBeforeAdd(plan: date) {
            let newPlan = PlanObj(plan: date)
            newPlan.parentPlan = parentPlan
            newPlan.level = level
            newPlan.content = content
            newPlan.date = title
            
            try! realm.write {
                realm.add(newPlan, update: .modified)
            }
        }
    }
    
    // 삭제시 실행되는 메소드
    func deletePlan(deletePlan: String) {
        var tmp: [String] = [deletePlan]
        var idx = 0
        
        repeat {
            let currentPlan = realm.objects(PlanObj.self).where {
                $0.plan == tmp[idx]
            }
            
            try! realm.write {
                realm.delete(currentPlan) // 여기서 문제가 발생
            }
            
            let deletePlan = realm.objects(PlanObj.self).where {
                $0.parentPlan == tmp[idx]
            }
            
            for obj in deletePlan {
                tmp.append(obj.plan)
            }
            
            idx += 1
        } while idx < tmp.count
    }
    
    func viewSubPlans(cell: PlanCollectionViewCell, index: Int, parent: String) -> PlanCollectionViewCell {
        let realm = try! Realm()
        
        // 중앙만 다른 값 처리
        if index == 4 {
            cell.configureCenter()
        }
        
        else {
            let planobj = realm.objects(PlanObj.self).where {
                $0.position == index &&
                $0.parentPlan == parent
            }.first
            
            if(planobj != nil) {
                //cell.backgroundColor = colors[index % 4]
                cell.configure(model: planobj!)
            } else {
                cell.configure_not_value()
            }
        }
        return cell
    }
    
}
