#include "main.hpp"

int main() {

    Pipe pipe;
    Peel peel;

    auto eval_frame = std::make_shared<EvaluateFrame>(1);
    pipe.addFrame(eval_frame);

    auto return_frame = std::make_shared<ReturningFrame>(nullptr); // ここではreturning frameのアドレスはnullptrを設定するが、実際には関数へのアドレスを設定する
    pipe.addFrame(return_frame);

    std::cout << "Frames in Pipe:" << std::endl;
    pipe.printFrames();

    peel.peelFrame(pipe);

    std::cout << "Peeled Frames:" << std::endl;
    peel.printPeeledFrames();

    return 0;
}
