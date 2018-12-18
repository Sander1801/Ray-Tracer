#ifndef __Engine_H_
#define __Engine_H_

class Engine
{
public:
	Engine();
	virtual ~Engine();

	bool OnCreate();
	void OnDestroy();

private:
	bool m_bIsRunning;
};

#endif // __Engine_H_

//////////////////////////////////////////////////////////////////////////
/*#define APPLICATION_ENTRY(appClass)									\
	int main()														\
	{																\
		Engine* app = new appClass();								\
		app->OnCreate();											\
		app->OnDestroy();											\
		delete app;													\
		return 0;													\
	} */
//////////////////////////////////////////////////////////////////////////