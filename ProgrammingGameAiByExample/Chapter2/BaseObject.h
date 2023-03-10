// -----------------------------------------------------------------------------
#ifndef BaseObject_H
#define BaseObject_H
// -----------------------------------------------------------------------------

//--INCLUDES--//


// -----------------------------------------------------------------------------

class BaseObjectInterface
{
public:
	virtual ~BaseObjectInterface() {}

	virtual void update() = 0;
};

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#endif // !BaseObject_H