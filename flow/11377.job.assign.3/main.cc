#include <climits>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solver {
 public:
  enum {
    kSource,
    kSink,
    kExtra,
    kWorker,
  };

  static constexpr int kWorkers = 1000;
  static constexpr int kWorks = 1000;
  static constexpr int kSeniors = 1000;
  static constexpr int kNodes = kWorker + kWorkers + kWorks;

  int Solve() {
    cin >> workers_ >> works_ >> extras_;

    Connect(kSource, kExtra, extras_);

    for (int works, worker = FirstWorker(); worker <= LastWorker(); worker++) {
      cin >> works;

      Connect(kSource, worker);
      Connect(kExtra, worker);

      for (int work; works-- > 0;) {
        cin >> work;
        Connect(worker, ToWorkId(work));
      }
    }

    for (int work = FirstWork(); work <= LastWork(); work++)
      Connect(work, kSink);

    return EdmondKarp();
  }

 private:
  int FirstWorker() { return kWorker; }

  int LastWorker() { return FirstWorker() + workers_ - 1; }

  int FirstWork() { return kWorker + workers_; }

  int LastWork() { return FirstWork() + works_ - 1; }

  int ToWorkId(int index) { return kWorker + workers_ + index - 1; }

  void Connect(int from, int to, int capacity = 1) {
    adj_[from].push_back(to);
    adj_[to].push_back(from);
    capacities_[from][to] = capacity;
  }

  int EdmondKarp(int source = kSource, int sink = kSink) {
    int flow = 0;

    while (true) {
      vector<int> parents(kNodes, -1);
      queue<int> queue;
      queue.push(source);
      parents[source] = source;

      while (!queue.empty() && parents[sink] == -1) {
        int from = queue.front();
        queue.pop();

        for (auto to : adj_[from]) {
          int residual = capacities_[from][to] - flows_[from][to];
          if (residual > 0 && parents[to] == -1) {
            parents[to] = from;
            queue.push(to);
          }
        }
      }

      if (parents[sink] == -1) break;

      int amount = INT_MAX;
      for (int p, c = sink; c != source; c = p) {
        p = parents[c];
        amount = min(amount, capacities_[p][c] - flows_[p][c]);
      }

      for (int p, c = sink; c != source; c = p) {
        p = parents[c];
        flows_[p][c] += amount;
        flows_[c][p] -= amount;
      }

      flow += amount;
    }

    return flow;
  }

  int workers_, works_, extras_;
  vector<int> adj_[kNodes];
  int capacities_[kNodes][kNodes];
  int flows_[kNodes][kNodes];
};
static Solver Solver;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cout << Solver.Solve() << endl;

  return 0;
}
