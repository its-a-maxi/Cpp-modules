#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat()
{
	return;
}

Bureaucrat::Bureaucrat( std::string const & name, int grade ) : _name(name), _grade(grade)
{
	if ( this->_grade < 1 )
		throw Bureaucrat::GradeToHighException();
	else if ( this->_grade > 150 )
		throw Bureaucrat::GradeToLowException();
	return;
}

Bureaucrat::Bureaucrat( const Bureaucrat & src ) : _name(src.getName()), _grade(src.getGrade())
{
	return;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
	return;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	if ( this != &rhs )
		this->_grade = rhs.getGrade();
	return ( *this );
}

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << ".";
	return ( o );
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void					Bureaucrat::incrementGrade( void )
{
	this->_grade -= 1;
	if ( this->_grade < 1 )
		throw Bureaucrat::GradeToHighException();
	else if ( this->_grade > 150 )
		throw Bureaucrat::GradeToLowException();
	return;
}

void					Bureaucrat::decrementGrade( void )
{
	this->_grade += 1;
	if ( this->_grade < 1 )
		throw Bureaucrat::GradeToHighException();
	else if ( this->_grade > 150 )
		throw Bureaucrat::GradeToLowException();
	return;
}

void					Bureaucrat::signForm( Form & form )
{
	if ( form.getGradeSign() < this->_grade )
		std::cout << this->_name << " cannot signs " << form.getName()
		<< " because his grade is too low." << std::endl;
	else if ( form.getSigned() )
		std::cout << this->_name << " cannot signs " << form.getName()
		<< " because it is already signed." << std::endl;
	else
		std::cout << this->_name << " signs "
		<< form.getName() << "." << std::endl;
	form.beSigned(*this);
	return;
}

void					Bureaucrat::executeForm( Form const & form )
{
	if ( form.getGradeExec() < this->_grade )
		std::cout << this->_name << " cannot executes " << form.getName()
		<< " because his grade is too low." << std::endl;
	else if ( !form.getSigned() )
		std::cout << this->_name << " cannot executes " << form.getName()
		<< " because it isn't signed." << std::endl;
	else
		std::cout << this->_name << " executes "
		<< form.getName() << "." << std::endl;
	form.execute(*this);
	return;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const &		Bureaucrat::getName( void ) const
{
	return ( this->_name );
}

int						Bureaucrat::getGrade( void ) const
{
	return ( this->_grade );
}


/* ************************************************************************** */