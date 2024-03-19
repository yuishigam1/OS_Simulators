#pragma once
#include<iostream>
#include<vector>

class CLookDiskSchedulingAlgo {
private:
    std::vector<int> target_tracks;
    int numOfTracks, startingTrack, coveredTracks;

    int getMaxTrack(std::vector<int> target_tracks) {
        int maxTrack = this->target_tracks[0];
        for (int i = 1; i < this->target_tracks.size(); i++) {
            if (maxTrack < this->target_tracks[i]) {
                maxTrack = this->target_tracks[i];
            }
        }
        return maxTrack;
    }
    int getMinTrack(std::vector<int> target_tracks) {
        int minTrack = this->target_tracks[0];
        for (int i = 1; i < this->target_tracks.size(); i++) {
            if (minTrack > this->target_tracks[i]) {
                minTrack = this->target_tracks[i];
            }
        }
        return minTrack;
    }

public:
    CLookDiskSchedulingAlgo(std::vector<int> target_tracks, int numOfTracks = 0, int startingTrack = 0) {
        this->target_tracks = target_tracks;
        this->numOfTracks = numOfTracks;
        this->startingTrack = startingTrack;
    }

    int getCoveredTracks(bool direction) {
        int minTrack = this->getMinTrack(this->target_tracks);
        int maxTrack = this->getMaxTrack(this->target_tracks);
        if (direction) {
            int lastMaxTrack = 0;
            for (int i = 0; i < this->target_tracks.size(); i++) {
                if (this->target_tracks[i] < this->startingTrack && this->target_tracks[i] > lastMaxTrack) {
                    lastMaxTrack = this->target_tracks[i];
                }
            }
            return (maxTrack - this->startingTrack) + (maxTrack - minTrack) + (lastMaxTrack - minTrack);
        }
        else {
            int lastMinTrack = this->numOfTracks;
            for (int i = 0; i < target_tracks.size(); i++) {
                if (this->target_tracks[i] > this->startingTrack && this->target_tracks[i] < lastMinTrack) {
                    lastMinTrack = this->target_tracks[i];
                }
            }
            return (this->startingTrack - minTrack) + (maxTrack - minTrack) + (maxTrack - lastMinTrack);
        }
    }
};