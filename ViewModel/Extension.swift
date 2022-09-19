//
//  Extension.swift
//  PlanningApp
//
//  Created by 이태곤 on 2022/09/02.
//

import Foundation
import UIKit

extension UIColor {
    class var randomColor: UIColor {
        return UIColor(
            red: CGFloat.random(in: 0.7...1),
            green: CGFloat.random(in: 0.7...1),
            blue: CGFloat.random(in: 0.7...1),
            alpha: 1
        )
    }
}
