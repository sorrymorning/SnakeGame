#ifndef CONTROLLER_H_
#define CONTROLLER_H_



class Controls: public QObject 
{
    Q_OBJECT
    public:
        Controls();

    private:
        UserAction_t convertKeyToAction(int key);
        void processUserInput(int key,bool hold);
}

#endif