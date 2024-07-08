#include <iostream>
#include <vector>
#include <string>

bool isFishSuccess = false;
bool isDivingSuccess = false;

class Player
{
public:
	Player(const std::string& name = "");
	~Player();
	void Score();
	void gotoFishing();
	void gotoDiving();
	void reactFishing();
	void reactDiving();
private:
	int score = 0;
	std::string m_Name;
};
Player::Player(const std::string& name) :m_Name(name) { }
Player::~Player() { }
void Player::Score()
{
	printf("player %s's scores are %d, congreatuation!\n", m_Name, score);
	std::cout << "player " << m_Name << "'s scores are " << score << ",congreatuation !!!" << std::endl;
}

void Player::gotoFishing()
{
	// player wants to go fishing
	// move to the pool
	// Throw bait into the water
}
void Player::reactFishing()
{
	if (!isFishSuccess)
	{
		// The fish had escaped.
	}
	else
	{
		score++;
		// fish catched
		// record fish's name
		// show fish
	}
}

void Player::gotoDiving()
{
	// palyer wants to go diving
	// move to the pool
	// jump to the pool
	// search for marine organism
}
void Player::reactDiving()
{
	if (!isDivingSuccess)
	{
		// jump out the pool
		// say sorry
	}
	else
	{
		// jump out the pool
		// record the fish
		// show the fish
	}
}

class Fish
{
public:
	Fish();
	~Fish();

	virtual void iscatched();
	virtual void escaped();
	virtual void catched();
protected:
	int rate = rand() % 10;	// 随机1-10
};
Fish::Fish() {}
Fish::~Fish() {}
void Fish::iscatched()
{
	if (rate <= 2)
	{
		isFishSuccess = false;
		escaped();
	}
	else
	{
		isFishSuccess = true;
		catched();
	}
}
void Fish::escaped()
{
	// fish escape
	// random new fish shade
}
void Fish::catched()
{
	// random fish's name
	// fish jump
	// random new fish shade
}


class DeepFish :public Fish
{
public:
	DeepFish();
	~DeepFish();

	virtual void iscatched();
	virtual void escaped();
	virtual void catched();
private:
	int rate = rand() % 10;	// 随机1-10
};


int main()
{
	std::string name;
	std::cout << "请输入玩家的名字呀~" << std::endl;
	std::cin >> name;
	Player player(name);
	Fish fish;
	std::cout << "请选择你的操作\n 0.去钓鱼\n 1.去潜水\n\n";
	int option;
	std::cin >> option;
	switch (option)
	{
	case 0:
		player.gotoFishing();
		fish.iscatched();
		player.reactFishing();
		break;
	case 1:
		player.gotoDiving();
		fish.iscatched();
		player.reactDiving();
		break;
	default:
		break;
	}
	player.Score();

	// fish.reaction


	return 0;
}