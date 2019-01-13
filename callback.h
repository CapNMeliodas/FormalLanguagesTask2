//Wanted to fo callback function...wanted
//It's useless for a while

#include <memory>

class Callback{
private:
	void (*function)(char*,void*);
	void  *parameters[4];

public:
	Callback(){
		function=[](char*,void*){
		};
	}

	template<class T>
	void operator=(T func){

		sizeof(int[ sizeof(parameters)-sizeof(T) ]);

		function=[](char* arg,void *param){
			(*(T*)param)(arg);
		};

		memcpy(parameters,&func,sizeof(T));
	}

	void operator()(char* d){
		function(d,parameters);
	}
};
