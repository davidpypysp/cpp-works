#include <stdio.h>
#include <iostream>
#include <deque>
#include <queue>

using namespace std;


class Job {
public: 
    string name;
    int arrive_time;
    int burst_time;
    int completion_time;
    int finished_time;
    int turn_around_time;
    int waiting_time;

    Job(string name, int arrive_time, int completion_time) {
        this->name = name;
        this->arrive_time = arrive_time;
        this->completion_time = completion_time;
        this->burst_time = completion_time;
    }
};


bool RoundRobin(int time_quantum, deque<Job> jobs_todo, deque<Job> &jobs_finished) {
    if(jobs_todo.empty()) return true;

    queue<Job> waiting;
    
    Job current_job = jobs_todo.front();
    jobs_todo.pop_front();
    int current_time = current_job.arrive_time;
    int cpu_finished_time = current_time + min(current_job.burst_time, time_quantum);
    current_job.burst_time -= min(current_job.burst_time, time_quantum);


    while(waiting.empty() == false || jobs_todo.empty() == false) {
        if(jobs_todo.empty() || cpu_finished_time < jobs_todo.front().arrive_time) {
            current_time = cpu_finished_time;
            cout << current_time << ": " << current_job.name << " cpu finished, rest: " << current_job.burst_time << endl;


            // cpu finish
            if(current_job.burst_time != 0) {
                waiting.push(current_job);
            }
            else {
                cout << current_job.name << " totally finished" << endl;
                current_job.finished_time = current_time;
                current_job.turn_around_time = current_time - current_job.arrive_time;
                current_job.waiting_time = current_job.turn_around_time - current_job.completion_time;
                jobs_finished.push_back(current_job);
            }
            

            if(waiting.empty() == false) {
                current_job = waiting.front();
                waiting.pop();
                if(current_job.burst_time < time_quantum) {
                    cpu_finished_time = current_time + current_job.burst_time;
                    current_job.burst_time = 0;
                }
                else {
                    cpu_finished_time = current_time + time_quantum;
                    current_job.burst_time -= time_quantum;
                }
            }
        }

        else {
            Job job = jobs_todo.front();
            current_time = job.arrive_time;
            cout << current_time << ": " << job.name << " insert to wait" << endl; 

            waiting.push(job);
            jobs_todo.pop_front();
            
        }
    }
    return true;

}


bool RoundRobin2(int time_quantum, deque<Job> jobs_todo, deque<Job> &jobs_finished) {
    if(jobs_todo.empty()) return true;

    queue<Job> waiting;
    
    bool cpu_running = false;
    bool cpu_finished_time = 0;


    while(waiting.empty() == false || jobs_todo.empty() == false) {
        if(cpu_running && !jobs_todo.empty() && cpu_finished_time < jobs_todo.front().arrive_time) {
            // push out
            current_time = cpu_finished_time;
            cpu_runing = false;
        }
        else {
            current_time = jobs_todo.front().arrive_time;
            // push front to waiting
        }

        if(cpu_running = false && waiting.empty() == false) {
            cpu_running = true;
            
        }

    }
    return true;

}
