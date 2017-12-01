
class Engine {
public:
    Engine() {}
    bool start() {return true;}
};

class Car {
public:
    Car(const Engine &engine) : engine(engine) {
    }

    bool turnKey() {
        return engine.start();
    }



private:
    Engine engine;

};