#ifndef INTERVIEW_FIND_ROUTINE
#define INTERVIEW_FIND_ROUTINE

#include <unordered_map>
#include <unordered_set>

class DiGraph
{
  std::unordered_map< int, std::unordered_set<int> > adjlist;
	std::unordered_set<int> visited;

	void setVisited(int src) {
		visited.insert(src);
	}

public:

  void add_edge(int src, int dst)
  {
		if (!exists(src)) {
			adjlist[src] = std::unordered_set<int>();
		}
    adjlist[src].insert(dst);
  }

  void remove_edge(int src, int dst)
  {
    if(adjlist.find(src) != adjlist.end()) {
      std::unordered_set<int>::iterator it = adjlist[src].find(dst);
      if (it != adjlist[src].end()) {
        adjlist[src].erase(it);
      }
    }
  }

	bool isVisited(int src) {
		return visited.find(src) != visited.end();
	}

  std::unordered_set<int> getLinks(int src)
  {
    if (adjlist.find(src) != adjlist.end()) {
      return adjlist[src];
    }
    return std::unordered_set<int>();
  }

  bool exists(int src)
  {
    return adjlist.find(src) != adjlist.end();
  }

  bool routineDFS(int src, int dst)
  {
    if (src == dst) return true;

    std::unordered_set<int> neighbors = getLinks(src);
    for(std::unordered_set<int>::iterator it = neighbors.begin();
        it != neighbors.end(); it++) {
			if (!isVisited(*it)) {
				if (routineDFS(*it, dst)) return true;
			}
			setVisited(*it);
    }
		return false;
  }

	bool hasRoutine(int src, int dst) {
		bool r;
		visited.clear();
		setVisited(src); // set src as visited
		r = routineDFS(src, dst);
		visited.clear();
		return r;
	}

	bool routineDFS(int src, int dst, std::vector<int>& path)
	{
		if (src == dst) {
			path.push_back(src);
			return true;
		}

    std::unordered_set<int> neighbors = getLinks(src);
    for(std::unordered_set<int>::iterator it = neighbors.begin();
        it != neighbors.end(); it++) {
			if (!isVisited(*it)) {
				if (routineDFS(*it, dst, path)){
					path.push_back(src);
					return true;
				}
			}
			setVisited(*it);
    }
		return false;
	}

	std::vector<int> findRoutine(int src, int dst) {
		std::vector<int> path;
		visited.clear();
		setVisited(src);
		routineDFS(src, dst, path);
		visited.clear();
		for(int i = 0; i < path.size()/2; i++) {
			int tmp = path[i];
			path[i] = path[path.size() - i - 1]; // index is [0, size - 1]
			path[path.size() - i - 1] = tmp;
		}
		return path;
	}

};


#endif
