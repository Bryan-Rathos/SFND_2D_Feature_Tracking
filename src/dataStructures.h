#ifndef dataStructures_h
#define dataStructures_h

#include <vector>
#include <opencv2/core.hpp>


struct DataFrame 
{ // represents the available sensor information at the same time instance
    
    cv::Mat cameraImg; // camera image
    
    std::vector<cv::KeyPoint> keypoints; // 2D keypoints within camera image
    cv::Mat descriptors; // keypoint descriptors
    std::vector<cv::DMatch> kptMatches; // keypoint matches between previous and current frame
};

template<typename FrameT>
class RingBuffer 
{
private:
    // Circular Queue
    uint bufSize;
    std::vector<FrameT> rBuff;

public:
    RingBuffer(uint sizeIn){
        bufSize = sizeIn;
    }

    void push_back(FrameT frame)
    { 
        if(rBuff.size()+1 <= bufSize){
            rBuff.push_back(frame);
        }
        else{
            rBuff.erase(rBuff.begin());
            rBuff.push_back(frame);
        }
    }

    typename std::vector<FrameT>::iterator end(){
        return rBuff.end();
    }

    uint size(){
        return rBuff.size();
    } 
};


#endif /* dataStructures_h */
