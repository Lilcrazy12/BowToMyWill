#include "frame.hpp"

class Frame;

class Pipe {
private:
    std::vector<std::shared_ptr<Frame>> frames;

public:
    void addFrame(std::shared_ptr<Frame> frame) {
        frames.push_back(frame);
    }

    void printFrames() const {
        for (const auto& frame : frames) {
            frame->printInfo();
        }
    }
};

class Peel {
private:
    std::vector<std::shared_ptr<Frame>> frames;

public:
    void peelFrame(Pipe& pipe) {
        if (!pipe.empty()) {
            frames.push_back(pipe.back());
            pipe.pop_back();
        }
    }

    void printPeeledFrames() const {
        for (const auto& frame : frames) {
            frame->printInfo();
        }
    }
};

class Frame {
public:
    virtual void printInfo() const = 0;
};
