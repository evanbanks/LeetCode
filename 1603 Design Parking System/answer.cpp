class ParkingSystem {
public:
    ParkingSystem(const int big, const int medium, const int small) 
        : big_ {big}, med_ {medium}, small_ {small}
    {}
    
    bool addCar(const int carType) {
        switch (carType) {
            case 3:
                if (small_) {
                    --small_;
                    return true;
                }
                break;
            case 2:
                if (med_) {
                    -- med_;
                    return true;
                }
                break;
            default:
                if (big_) {
                    -- big_;
                    return true;
                }
                break;
        }
        return false;
    }
private:
    int big_;
    int med_;
    int small_;
};