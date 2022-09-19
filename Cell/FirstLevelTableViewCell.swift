//
//  FirstLevelTableViewCell.swift
//  PlanningApp
//
//  Created by 이태곤 on 2022/09/13.
//

import UIKit

class FirstLevelTableViewCell: UITableViewCell {
    @IBOutlet weak var indexLabel: UILabel!
    @IBOutlet weak var planLabel: UILabel!
    @IBOutlet weak var percentageLabel: UILabel!
    
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)
    }

    func configure(plan: PlanObj, index: Int) {
        indexLabel.text = String(index + 1)
        planLabel.text = plan.plan
        percentageLabel.text = "0%"
    }
}
