//
//  PlanCollectionViewCell.swift
//  PlanningApp
//
//  Created by 이태곤 on 2022/08/24.
//

import UIKit

class PlanCollectionViewCell: UICollectionViewCell {
    @IBOutlet weak var achievementLabel: UILabel!
    @IBOutlet weak var subPlanLabel: UILabel!
    @IBOutlet weak var addView: UIImageView!
    
    
    // view의 모양 설정
    // Label 2개에 대한 값 설정
    func configure (model: PlanObj) {
        subPlanLabel.text = model.plan
        var percentage: String
        model.level < 3 ? (percentage = String(model.percent) + "%") : (percentage = "")
        achievementLabel.text = percentage
        contentView.backgroundColor = colors[model.position! % 4]
        contentView.layer.cornerRadius = 20
        contentView.layer.borderWidth = 0
        addView.image = .none
    }
    
    func configure_not_value(){
        achievementLabel.text = ""
        subPlanLabel.text = ""
        contentView.layer.cornerRadius = 20
        contentView.backgroundColor = UIColor.clear
        contentView.layer.borderColor = UIColor.darkGray.cgColor
        contentView.layer.borderWidth = 1
        
        addView.tintColor = UIColor.black
        addView.image = UIImage(systemName: "plus")
    }
    
    // VM에서 평균 퍼센트 계산해줘서 input으로 넣어줌
    // 여기에 퍼센트도 추가하는거 입력
    func configureCenter() {
        achievementLabel.text = ""
        subPlanLabel.text = "0%"
        contentView.layer.cornerRadius = 20
        contentView.backgroundColor = .none
        contentView.layer.borderWidth = 0
        addView.image = UIImage()
    }
}
