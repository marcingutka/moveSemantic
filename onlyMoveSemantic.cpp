class onlyMove
{
    public:
        onlyMove(int* p) : member(p){}
        onlyMove (const onlyMove &source) = delete;

        onlyMove(onlyMove && source)
        {
            member = source.member;
            source.member = nullptr;
        }

        onlyMove & operator=(onlyMove && source)
        {
            member = source.member;
            source.member = nullptr;
            return *this;
        }

    private:
        int* member;
};

main()
{
    onlyMove w1(new int(3));
    onlyMove w2(std::move(w1));
    onlyMove w3(new int(6));
    w3 = std::move(w2);

    return 0;
}
