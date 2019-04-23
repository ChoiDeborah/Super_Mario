#pragma once
class CCollisionMgr
{
public:
	CCollisionMgr();
	~CCollisionMgr();

public:
	static void CollisionRect(OBJLIST& DestList, OBJLIST& SourList, OBJID::ID eDestID, OBJID::ID eSourID);
	
	
public:
	static void CollisionRect_Coin(OBJLIST& DestList, OBJLIST& SourList, BACKGROUNDID::ID eDestID, OBJID::ID eSourID);
	static void CollisionRect_SizeUp(OBJLIST& DestList, OBJLIST& SourList, BACKGROUNDID::ID eDestID, OBJID::ID eSourID);
	static void CollisionRect_SizeUp_And_Bullet(OBJLIST& DestList, OBJLIST& SourList, BACKGROUNDID::ID eDestID, OBJID::ID eSourID);
	static void CollisionRect_LifeUp(OBJLIST& DestList, OBJLIST& SourList, BACKGROUNDID::ID eDestID, OBJID::ID eSourID);
	static void CollisionRect_LifeDamege(OBJLIST& DestList, OBJLIST& SourList, BACKGROUNDID::ID eDestID, OBJID::ID eSourID);
	static void CollisionRect_Tile(OBJLIST& DestList, OBJLIST& SourList, BACKGROUNDID::ID eDestID, OBJID::ID eSourID);

public:
	static void CollisionRectEX(OBJLIST& DestList, OBJLIST& SourList, OBJID::ID eDestID, OBJID::ID eSourID);
	static void CollisionRectEX(OBJLIST& DestList, OBJLIST& SourList, BACKGROUNDID::ID eDestID, OBJID::ID eSourID);
	static void CollisionSphere(OBJLIST& DestList, OBJLIST& SourList, OBJID::ID eDestID, OBJID::ID eSourID);
	
	


public:
	static void CollisionRectExWithPlayer_OBJ(OBJLIST& ObjtList, OBJID::ID eOBJID);
	static void CollisionRectExWithPlayer_BACKGROUND(OBJLIST& ObjtList, BACKGROUNDID::ID eOBJID);


private:
	static bool CheckSphere(CObj* pDest, CObj* pSour);
	static bool CheckRect(CObj* pDest, CObj* pSour, float* pMoveX, float* pMoveY);
};

