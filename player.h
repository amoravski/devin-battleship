class Player
{
    public:
        std::string getName( void);
        int getTurn( void );
        int getNumber( void );
        Player(int);
    private:
        std::string name;
        bool first;
        int turn;
        int num;
};
