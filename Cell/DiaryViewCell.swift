//
//  DiaryViewCell.swift
//  PlanningApp
//
//  Created by 이태곤 on 2022/09/13.
//

import UIKit

class DiaryViewCell: UICollectionViewCell {
    
    @IBOutlet weak var dateLabel: UILabel!
    @IBOutlet weak var contentLabel: UILabel!
    
    func configure(plan: PlanObj, date: String) {
//        let formatter = DateFormatter()
//        formatter.dateFormat = "MMM d, yyyy"
        dateLabel.text = date
        
        contentLabel.text = plan.date
    }
}
