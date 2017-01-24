//
//  ViewController.swift
//  trafficLight
//
//  Created by Julia Liu on 2017-01-10.
//  Copyright © 2017 Julia Liu. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    
    @IBOutlet var trafficLight: UIImageView!
    @IBOutlet var counterLabel: UILabel!
    @IBOutlet var startStopBotton: UIButton!
    @IBOutlet var trafficLight2: UIImageView!
    @IBOutlet var trafficLight1: UIImageView!
    
    var timer = Timer()
    var scoreTime = Timer()
    var timerInt = 0
    var scoreInt = 0
    
    
    
    //the viewDidLoad function is the function that itianlly run when the app is started, setting initial values int here
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        
        scoreInt = 0
        counterLabel.text = String(scoreInt) //setting lable to zero
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    
    //the function below is the action of the button not an ordinary function, it will execute every time pressed
    
    @IBAction func StartStop(_ sender: Any) {
        
        if scoreInt == 0 {
            timerInt = 3
            trafficLight.image = UIImage(named: "hamster3" )
            trafficLight1.image = UIImage(named: "hamster3")
            trafficLight2.image = UIImage(named: "hamster3")
            //for restarting the game
            
            //created a thread to execute the function updateCounter, while the current thread continues to run.
            //It will disable the button, until the updateCounter gets to timerInt == 0 and re-enables the button
            
            timer = Timer.scheduledTimer(timeInterval: 1, target: self, selector: #selector(ViewController.updateCounter), userInfo: nil, repeats: true)
            
            startStopBotton.isEnabled = false
            startStopBotton.setTitle("", for: [])
            
            counterLabel.textColor = UIColor.white
            counterLabel.text = String(scoreInt)
        }
            
        else {
            scoreTime.invalidate()
            counterLabel.text = "You Score is " + String(scoreInt)
            counterLabel.textColor = UIColor.red
        }
        
        if timerInt == 0 {
            
            scoreInt = 0
            //counterLabel.text = String(scoreInt)
            startStopBotton.setTitle("Restart", for: [])
            
            
        }
        
        
    }
    
    
    
    func updateCounter () {
        
        timerInt -= 1
        
        if timerInt == 2 {
            trafficLight1.image = UIImage(named: "")
        }
        
        else if timerInt == 1 {
            trafficLight2.image = UIImage (named: "")
            
            startStopBotton.setTitle("Stop", for: [])
        }
        
        else if timerInt == 0 {
            trafficLight.image = UIImage(named: "")
            
            timer.invalidate()
            startStopBotton.isEnabled = true
            
            scoreTime = Timer.scheduledTimer(timeInterval: 0.0001, target: self, selector: #selector(ViewController.updateScoreTimer), userInfo: nil, repeats: true)
        }
        
    }
    
    func updateScoreTimer () {
        
        scoreInt += 1
        counterLabel.text = String(scoreInt)
        
        
        
    }

}

