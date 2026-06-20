class Car{
public:
    int carPosition;
    double timeToReachDestination;

    Car(int a, double b){
        carPosition = a;
        timeToReachDestination = b;
    }
};

class Solution {
public:
    static bool customComparison(Car a, Car b){
        return a.carPosition < b.carPosition;
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car> arr;
        for(int i = 0; i < position.size(); i++){
            double time = ((double)(target - position[i])) / speed[i];
            arr.push_back(Car(position[i], time));
        }

        sort(arr.begin(), arr.end(), customComparison);

        int ans = 0;
        for(int i = arr.size() - 1; i >= 1; i--){
            if(arr[i].timeToReachDestination >= arr[i-1].timeToReachDestination){
                arr[i-1] = arr[i];
            } else {
                ans++;
            }
        }

        return ans+1;
    }
};