#ifndef AGR_EH2B_TYPES_HPP
#define AGR_EH2B_TYPES_HPP

struct Base {
    int base;
    explicit Base(int value = 0) : base(value) {}
    virtual ~Base();
};

struct Left {
    int left;
    explicit Left(int value = 0) : left(value) {}
    virtual ~Left();
};

struct Right {
    int right;
    explicit Right(int value = 0) : right(value) {}
    virtual ~Right();
};

struct Derived : Base, Left, Right {
    int derived;
    explicit Derived(int seed = 0)
        : Base(seed + 1), Left(seed + 2), Right(seed + 3), derived(seed + 4) {}
    virtual ~Derived();
};

struct Wrong {
    int value;
    explicit Wrong(int v = 0) : value(v) {}
    virtual ~Wrong();
};

#endif
