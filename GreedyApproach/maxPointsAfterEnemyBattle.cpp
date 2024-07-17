// question : https://leetcode.com/problems/maximum-points-after-enemy-battles/ 

/*
Example 1 :
Input: enemyEnergies = [3,2,2], currentEnergy = 2
Output: 3

Example 2:
Input: enemyEnergies = [2], currentEnergy = 10
Output: 5

 */

class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
     int i =0;
     int j =enemyEnergies.size()-1;
     long long points = 0;
     long long energy = currentEnergy;
     sort(enemyEnergies.begin(),enemyEnergies.end());
     if(energy<enemyEnergies[0]) return 0;
     while(i<=j){
        if(energy>=enemyEnergies[i]){
            points+=energy/enemyEnergies[i];
            energy = energy%enemyEnergies[i];
        } 
        else{
            energy+=enemyEnergies[j];
            j--;
        }
     }
     return points;   
    }
};