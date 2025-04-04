#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

struct Message {
    enum Type { START, STOP, KEEP, TEXT, ABORT, BUSY } type;
    int client_id;
    uint32_t sequence;
    char text[256];
};

class Communication {

    public:
        bool GetMessage(std::unique_ptr<Message>& msg, unsigned timeout);
        void SendMessage(const Message& msg);
};

class Server {
    private:
        Communication communication;
    public:
        void Run() {
            while (true) {
                std::unique_ptr<Message> msg;
                if (!communication.GetMessage(msg, 1000)) continue;


                if (msg->type == Message::START) {

                } else if (msg->type == Message::STOP) {

                }
            }
        };
};