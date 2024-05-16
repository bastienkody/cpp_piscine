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

//	it empties the stack, be carefull
void	RPN::printStack()
{
	while(_stack.empty() == false)
		{std::cout << _stack.top(); _stack.pop();}
}

//	parametric constructor, runs the "main"/whole process
RPN::RPN(const std::string data)
{
	std::string					tmp;
	std::string::const_iterator it = data.begin();

	if (it == data.end())
		throw std::invalid_argument("Error: empty argument");

	while(it != data.end())
	{
		while(it != data.end() && isspace(*it))
			++it;
		while(it != data.end() && !isspace(*it))
		{
			tmp += *it;
			++it;
		}
		if (tmp.empty() == true)
			continue;
		if (isValidDigit(tmp) == false && isValidOperator(tmp) == false)
			throw std::invalid_argument("Error: bad operator/operand: " + tmp);
		_stack.push(tmp);
		//std::cout << "just inserted " << tmp << std::endl;
		tmp.clear();
		calculate();
	}
	if (_stack.size() != 1)
		throw std::invalid_argument("Error: bad argument format (stack.size != 1 after all input processed)");
	std::cout << extractStrFromStackToDouble() <<  std::endl;
}

//	if top is operator : extract, doOp, put res (checked via sstream) in stack
void	RPN::calculate()
{
	std::stringstream	ssres;
	char				op;
	double				lhs, rhs, res;

	if (isValidOperator(_stack.top()) == false)
		return ;

	op = _stack.top()[0];
	_stack.pop();
	rhs = extractStrFromStackToDouble();
	lhs = extractStrFromStackToDouble();

	ssres << doOperation(lhs, rhs, op);
	ssres >> res;
	if (ssres.fail() == true || ssres.eof() == false)
		throw std::runtime_error("Error: result of an operation does not fit in a double");
	ssres << res;	
	_stack.push(ssres.str());
	ssres.clear();
}

double	RPN::doOperation(double lhs, double rhs, char op) const
{
	//std::cout << lhs << op << rhs << std::endl;
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
			throw std::runtime_error("default reached in doOperation, SHOULD BE IMPOSSIBLE");
	}
}

double	RPN::extractStrFromStackToDouble()
{
	if (_stack.empty() == true)
		throw std::invalid_argument("Error: bad argument (unexpected empty stack)");

	double					d;
	std::stringstream		sstop(_stack.top());

	_stack.pop();
	sstop >> d;
	if (sstop.fail() || !sstop.eof())
		throw std::invalid_argument("Error: bad argument (digit does not fit into a double)");
	return d;
}

bool	RPN::isValidOperator(std::string val) const
{
	std::string	ok[4] = {"+", "-", "/", "*"};

	for (unsigned int i = 0; i < 4; ++i)
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
