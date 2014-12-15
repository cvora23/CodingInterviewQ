/*
 * ReaderWriterLock.cpp
 *
 *  Created on: Dec 15, 2014
 *      Author: cvora
 */

class Lock{
public:
	void Acquire(){

	}
	void Release(){

	}
};

class Condition{
public:
	void Wait(Lock& lock){

	}
	void Signal(){

	}
	void Broadcast(){

	}
};

class SharedLock{

private:
	int readers; // #active readers or -1 if writer.
	Lock rwMx;
	Condition rwCv;
	bool writer;

public:

	void AcquireRead(); // shared mode
	void AcquireWrite(); // exclusive mode
	void ReleaseRead();
	void ReleaseWrite();
};

void SharedLock::AcquireWrite(){
	// exclusive mode

	rwMx.Acquire();
	while(writer || (readers > 0)){
		rwCv.Wait(rwMx);
	}
	writer = true;
	rwMx.Release();

}

void SharedLock::ReleaseWrite()
{
	rwMx.Acquire();
	writer = false;
	rwCv.Broadcast();
	rwMx.Release();
}


void SharedLock::AcquireRead(){
	// shared mode

	rwMx.Acquire();
	while(writer){
		rwCv.Wait(rwMx);
	}

	readers++ ;

	rwMx.Release();

}

void SharedLock::ReleaseRead(){

	rwMx.Acquire();
	readers--;

	if(readers == 0){
		rwCv.Broadcast();
	}

	rwMx.Release();

}




