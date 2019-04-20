class Player
{
    public:
        std::string getName();
        int getTurn();
        int getNumber();
        Player(int);
    private:
        std::string name;
        bool first;
        int turn;
        int num;
};
