#ifndef _AGENT_HH_
#define _AGENT_HH_

#include <global.h>

class Environment;

class Agent{
public:
	static Environment* _myEnv;
	
private:
    uint32_t id;
    CoordXY  coordxy;
	State state[2];
	Neighbors agentNeighbors;

public:
	
	Agent(const uint32_t&, const float);
	
    ~Agent(void);

    CoordXY  getCoordxy(void) const;
	void     setCoordxy(const CoordXY& );
	uint32_t getId(void) const;

	State& getState();
	
	void applyRules(uint32_t a);
	void update();

	Neighbors& getNeighbors() { return agentNeighbors; }	
	void setNeighbors( const Neighbors);
	
	friend std::ostream& operator<<(std::ostream&,  Agent*);

	
private:
	float getLivingNeighbors();
	float getLivingNeighborsVectorial();

};
#endif
