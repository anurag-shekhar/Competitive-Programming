/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : RobotRoomCleaner.cpp
 * Created on : Tue Jun 15 2021
 ****************************************************************
 */


/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    unordered_set<string> visited;
    vector<vector<int> > dir;
    void clean(int x, int y, int arrow, Robot& robot)
    {   
        string hash = to_string(x) + "," + to_string(y);
        if(!visited.count(hash))
        {
            robot.clean();
            visited.insert(hash);
            
            for(int i = 0; i<4; i++)
            {
                if(robot.move())
                    clean(x+dir[arrow][0],y+dir[arrow][1],arrow, robot);
                robot.turnLeft();
                arrow++;
                arrow %=4;
            }
        }
        robot.turnLeft();
        robot.turnLeft();
        robot.move();
        robot.turnLeft();
        robot.turnLeft();
    }
    void cleanRoom(Robot& robot) {
        
        robot.clean();
        dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        
        clean(0,0,0,robot);
    }
};
