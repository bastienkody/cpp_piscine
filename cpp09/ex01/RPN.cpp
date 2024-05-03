#include"RPN.hpp"

RPN::RPN()
{
}
RPN::~RPN()
{
}
RPN::RPN(const RPN & src)
{
	*this = src;
}
RPN & RPN::operator=(const RPN & rhs)
{
	if(this != &rhs)
		_stack = rhs._stack;
	return (*this);
}

//	empties the stack be carefull
void	RPN::printStack()
{
	while(_stack.empty() == false)
		{std::cout << _stack.top(); _stack.pop();}
}

//	parametric constructor, read av[1] into _stack, throw 
RPN::RPN(const std::string data)
{
	std::string					tmp;
	std::string::const_reverse_iterator rit = data.rbegin();

	if (rit == data.rend())
		throw std::invalid_argument("Error: empty argument");

	while(rit != data.rend())
	{
		while(rit != data.rend() && isspace(*rit))
			++rit;
		while(rit != data.rend() && !isspace(*rit))
		{
			tmp += *rit;
			++rit;
		}
		if (isValidDigit(tmp) == false && isValidOperator(tmp) == false)
			throw std::invalid_argument("Error: bad operator/operand: " + tmp);
		_stack.push(tmp);
		tmp.clear();
	}
}

std::string	copy(std::string src)
{
	std::string res;

	for (std::string::const_iterator it = src.begin(); it != src.end(); ++it)
		res += *it;
	return res;
}

void	RPN::calculate()
{
	std::stack<std::string>	buf;
	std::stringstream		sstr2;
	double					lhs, rhs, res;
	char					op;

	while(_stack.size() != 1)
	{
		//std::cout << "stack size + top:" << _stack.size() << " : " << _stack.top() << std::endl;
		while(_stack.size() > 1 && isValidOperator(_stack.top()) == false)
		{
			//std::cout << _stack.top() << std::endl;
			buf.push(_stack.top());
			_stack.pop();
		}
		op = _stack.top()[0];
		_stack.pop();
		std::cout << "buf size before l/rhs : " << buf.size() << std::endl;
		lhs = extractStrFromStackToDouble(buf);
		rhs = extractStrFromStackToDouble(buf);
		sstr2 << doOperation(lhs, rhs, op);
		_stack.push(sstr2.str());
		sstr2.clear();
	}

	std::stringstream sstr(_stack.top());
	sstr >> res;
	if (sstr.fail() || !sstr.eof())
		throw std::invalid_argument("Error (sstr >> res)");
	std::cout << "res:" << res << std::endl;
}

double	RPN::doOperation(double lhs, double rhs, char op) const
{
	switch (op)
	{
		case '+':
			return (lhs + rhs);
		case '-':
			return (lhs - rhs);
		case '*':
			return (lhs * rhs);
		case '/':
			return (lhs / rhs);
		default:
			throw std::runtime_error("default reached in doOperation, ABNORMAL");
	}
}

double	RPN::extractStrFromStackToDouble(std::stack<std::string> &buf) const
{
	if (buf.empty() == true)
		throw std::invalid_argument("Error (buf empty)");

	double					d;
	std::stringstream		sstop(buf.top());

	buf.pop();
	sstop >> d;
	if (sstop.fail() || !sstop.eof())
		throw std::invalid_argument("Error (sstop >> d)");
	return d;
}


bool	RPN::isValidOperator(std::string val) const
{
	std::string	ok[4] = {"+", "-", "/", "*"};

	for (uint i = 0; i < 4; ++i)
		if (val.compare(ok[i]) == 0)
			return true;
	return false;
}

bool	RPN::isValidDigit(std::string val) const
{
	std::stringstream	sVal(val);
	double				d;

	sVal >> d;
	if (sVal.fail() || !sVal.eof() || d < -9 || d > 9)
		return false;
	return true;
}