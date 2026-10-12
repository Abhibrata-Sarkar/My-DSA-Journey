class BusBooking {
public:
    int minTime = 0, totalTime = 0;
    vector<vector<bool>> booking;
    vector<vector<int>> time;

    BusBooking(int n) {
        booking = vector<vector<bool>>(n, vector<bool>(4, 0));
        time = vector<vector<int>>(n, vector<int>(4, 0));
    }
    
    void toggle(string seat) {
        int col = seat[0] - 'A';
        int row = stoi(seat.substr(1)) - 1;

        if(booking[row][col] == false){
            booking[row][col] = true;

            if(col == 1 || col == 2){
                minTime++;
                totalTime++;
            }
            else{
                minTime++;

                if(col == 0 && booking[row][1] == true){
                    totalTime += 3;
                    time[row][col] = 3;
                }
                else if(col == 3 && booking[row][2] == true){
                    totalTime += 3;
                    time[row][col] = 3;
                }
                else{
                    totalTime++;
                    time[row][col] = 1;
                }
            }   
        }
        else{
            booking[row][col] = false;

            if(col == 1 || col == 2){
                minTime--;
                totalTime--;
            }
            else{
                minTime--;

                if(time[row][col] == 3) totalTime -= 3;
                else totalTime--;
            }              
        }
    }
    
    int getTotalTime() {
        return totalTime;
    }
    
    int getMinTime() {
        return minTime;
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */