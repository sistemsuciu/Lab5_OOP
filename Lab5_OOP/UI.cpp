// This header contains the definition of the class "UI".
#include "UI.h"
#include "Watchlist.h"
#include <iostream>

UI::UI()
{
}

UI::~UI()
{
}

void UI::printMenu()
{
	// This method prints the main menu.
	std::cout << std::endl;
	std::cout << "Main menu:" << std::endl;
	std::cout << "   1 - Admin menu;" << std::endl;
	std::cout << "   2 - User menu;" << std::endl;
	std::cout << "   0 - Exit." << std::endl;
	std::cout << "Choose an option. ";
}

void UI::printAdminMenu()
{
	// This method prints the admin menu.
	std::cout << std::endl;
	std::cout << "Admin menu:" << std::endl;
	std::cout << "   1 - Add a new movie;" << std::endl;
	std::cout << "   2 - Delete a movie;" << std::endl;
	std::cout << "   3 - Modify a movie's title;" << std::endl;
	std::cout << "   4 - Modify a movie's genre;" << std::endl;
	std::cout << "   5 - Modify a movie's number of likes;" << std::endl;
	std::cout << "   6 - Modify a movie's trailer;" << std::endl;
	std::cout << "   7 - See all the movies;" << std::endl;
	std::cout << "   0 - Back to the main menu." << std::endl;
	std::cout << "Choose an option: ";
}

void UI::printUserMenu()
{
	// This method prints the user menu.
	std::cout << std::endl;
	std::cout << "User menu:" << std::endl;
	std::cout << "   1 - See the movies with a given genre;" << std::endl;
	std::cout << "   2 - See all the movies;" << std::endl;
	std::cout << "   3 - See the movies from the watchlist;" << std::endl;
	std::cout << "   4 - Delete a movie from the watchlist;" << std::endl;
	std::cout << "   0 - Back to the main menu." << std::endl;
	std::cout << "Choose an option: ";
}

void UI::AddMovie()
{
	// This method adds a movie in the list of movies.
	std::string title, genre, trailer, tempStr;
	int apparition_year, number_of_likes = 0, ID;
	std::cout << "ID: ";
	getline(std::cin, tempStr);
	ID = atoi(tempStr.c_str());
	while (ID)
	{
		if ((this->ctrl.number_validation(ID)) == false)
		{
			std::cout << "The ID must be an positive integer number!" << std::endl;
			std::cout << "Retype the ID: ";
			getline(std::cin, tempStr);
			ID = atoi(tempStr.c_str());
		}
		else if ((this->ctrl.find_movie(ID)) == true)
		{
			std::cout << "This ID is already in use for another movie." << std::endl;
			std::cout << "Retype the ID: ";
			getline(std::cin, tempStr);
			ID = atoi(tempStr.c_str());
		}
		else
			break;
	}
	std::cout << "Title: ";
	getline(std::cin, title);
	std::cout << "Genre: ";
	getline(std::cin, genre);
	std::cout << "Apparition year: ";
	getline(std::cin, tempStr);
	apparition_year = atoi(tempStr.c_str());
	while (apparition_year)
	{
		if ((this->ctrl.year_validation(apparition_year)) == false)
		{
			std::cout << "The year must be an integer between 1895 and 2018." << std::endl;
			std::cout << "Retype the year: ";
			getline(std::cin, tempStr);
			apparition_year = atoi(tempStr.c_str());
		}
		else
			break;
	}
	std::cout << "Trailer: ";
	getline(std::cin, trailer);
	this->ctrl.add_movie_to_repository(ID, title, genre, apparition_year, number_of_likes, trailer);
	std::cout << "Added!" << std::endl;
}

void UI::DeleteMovie()
{
	// This method deletes a movie from the list.
	std::cout << "Type the ID of the movie that you want to delete: ";
	int ID;
	std::string temp;
	getline(std::cin, temp);
	ID = atoi(temp.c_str());
	while (ID)
	{
		if ((this->ctrl.number_validation(ID) == false))
		{
			std::cout << "The ID must be a positive integer." << std::endl;
			std::cout << "Retype the ID: ";
			getline(std::cin, temp);
			ID = atoi(temp.c_str());
		}
		else if ((this->ctrl.find_movie(ID) == false))
		{
			std::cout << "No movie with the given ID was found." << std::endl;
			std::cout << "Retype the ID: ";
			getline(std::cin, temp);
			ID = atoi(temp.c_str());
		}
		else
			break;
	}
	std::cout << "The movie with the ID " << ID << " was successfully deleted!" << std::endl;
	this->ctrl.delete_movie_from_repository(ID);
}

void UI::DeleteMovieFromWatchlist()
{
	// This method deletes a movie from the watchlist.
	DynamicVector vector = this->ctrl.get_watchlist_repo().getMovies();
	Movie* movie = vector.getAllElems();
	if (movie == NULL)
		return;
	if (vector.getSize() == 0)
	{
		std::cout << "There are no movies in the database." << std::endl;
		return;
	}

	std::cout << "Type the ID of the movie that you want to delete: ";
	int ID;
	std::string temp;
	getline(std::cin, temp);
	ID = atoi(temp.c_str());
	while (ID)
	{
		if ((this->ctrl.number_validation(ID) == false)) // if the ID is not a valid number
		{
			std::cout << "The ID must be a positive integer." << std::endl;
			std::cout << "Retype the ID: ";
			getline(std::cin, temp);
			ID = atoi(temp.c_str());
		}
		else if ((this->ctrl.find_movie(ID) == false)) // if the ID doesn't correspond to a movie
		{
			std::cout << "No movie with the given ID was found." << std::endl;
			std::cout << "Retype the ID: ";
			getline(std::cin, temp);
			ID = atoi(temp.c_str());
		}
		else // if the ID is valid
		{
			// deletes the movie with the given ID
			std::cout << "The movie with the ID " << ID << " was successfully deleted!" << std::endl;
			this->ctrl.delete_movie_from_watchlist(ID);

			std::cout << "Would you like to give a like to the movie? Type Yes or No." << std::endl;
			std::string option;
			getline(std::cin, option);
			bool condition = true;
			while (condition)
			{
				if (option == "Yes" || option == "yes") // if the user wants to give a like to the movie
				{
					int new_number;

					for (int i = 0; i < vector.getSize(); i++)
					{
						Movie m = movie[i];
						if (m.get_id() == ID)
						{
							new_number = m.get_number_of_likes();
							new_number++; // we are increasing the number of likes of the movie
						}
					}

					this->ctrl.update_number_of_likes(ID, new_number);
					std::cout << "The number of likes was successfully modified!" << std::endl;
					std::cout << "Press any key to continue." << std::endl;
					condition = false;
				}
				else if (option == "No" || option == "no") // if the user doesn't want to give a like to the movie
				{
					std::cout << "The number of likes was not modified." << std::endl;
					std::cout << "Press any key to continue." << std::endl;
					condition = false;
				}
				else
				{
					std::cout << "Invalid option." << std::endl;
					std::cout << "Retype the option: ";
					getline(std::cin, option);
				}
			}
			break;
		}
	}


}

void UI::UpdateTitle()
{
	// This method modifies the title of a movie.
	std::cout << "Type the ID of the movie: ";
	int ID;
	std::string temp;
	getline(std::cin, temp);
	ID = atoi(temp.c_str());
	while (ID)
	{
		if ((this->ctrl.number_validation(ID) == false))
		{
			std::cout << "The ID must be a positive integer." << std::endl;
			std::cout << "Retype the ID: ";
			getline(std::cin, temp);
			ID = atoi(temp.c_str());
		}
		else if ((this->ctrl.find_movie(ID) == false))
		{
			std::cout << "No movie with the given ID was found." << std::endl;
			std::cout << "Retype the ID: ";
			getline(std::cin, temp);
			ID = atoi(temp.c_str());
		}
		else
			break;
	}
	std::cout << "Type the new title: ";
	std::string new_title;
	getline(std::cin, new_title);
	this->ctrl.update_title(ID, new_title);
	std::cout << "The name of the movie with the ID " << ID << " has been successfully modified!" << std::endl;
}

void UI::UpdateGenre()
{
	// This method modifies the genre of a movie.
	std::cout << "Type the ID of the movie: ";
	int ID;
	std::string temp;
	getline(std::cin, temp);
	ID = atoi(temp.c_str());
	while (ID)
	{
		if ((this->ctrl.number_validation(ID) == false))
		{
			std::cout << "The ID must be a positive integer." << std::endl;
			std::cout << "Retype the ID: ";
			getline(std::cin, temp);
			ID = atoi(temp.c_str());
		}
		else if ((this->ctrl.find_movie(ID) == false))
		{
			std::cout << "No movie with the given ID was found." << std::endl;
			std::cout << "Retype the ID: ";
			getline(std::cin, temp);
			ID = atoi(temp.c_str());
		}
		else
			break;
	}
	std::cout << "Type the new genre: ";
	std::string new_genre;
	getline(std::cin, new_genre);
	this->ctrl.update_genre(ID, new_genre);
	std::cout << "The genre of the movie with the ID " << ID << " has been successfully modified!" << std::endl;
}

void UI::UpdateNumberOfLikes()
{
	// This method modifies the number of likes of a movie.
	std::cout << "Type the ID of the movie: ";
	int ID;
	std::string temp;
	getline(std::cin, temp);
	ID = atoi(temp.c_str());
	while (ID)
	{
		if ((this->ctrl.number_validation(ID) == false))
		{
			std::cout << "The ID must be a positive integer." << std::endl;
			std::cout << "Retype the ID: ";
			getline(std::cin, temp);
			ID = atoi(temp.c_str());
		}
		else if ((this->ctrl.find_movie(ID) == false))
		{
			std::cout << "No movie with the given ID was found." << std::endl;
			std::cout << "Retype the ID: ";
			getline(std::cin, temp);
			ID = atoi(temp.c_str());
		}
		else
			break;
	}
	std::cout << "Type the new number of likes: ";
	int number;
	getline(std::cin, temp);
	number = atoi(temp.c_str());
	while (number)
	{
		if (this->ctrl.number_validation(number) == false)
		{
			std::cout << "The number of likes must be a positive integer." << std::endl;
			std::cout << "Retype the number of likes: ";
			getline(std::cin, temp);
			number = atoi(temp.c_str());
		}
		else
			break;
	}
	this->ctrl.update_number_of_likes(ID, number);
	std::cout << "The number of likes of the movie with the ID " << ID << " has been successfully modified!" << std::endl;
}

void UI::UpdateTrailer()
{
	// This method modifies the trailer of a movie.
	std::cout << "Type the ID of the movie: ";
	int ID;
	std::string temp;
	getline(std::cin, temp);
	ID = atoi(temp.c_str());
	while (ID)
	{
		if ((this->ctrl.number_validation(ID) == false))
		{
			std::cout << "The ID must be a positive integer." << std::endl;
			std::cout << "Retype the ID: ";
			getline(std::cin, temp);
			ID = atoi(temp.c_str());
		}
		else if ((this->ctrl.find_movie(ID) == false))
		{
			std::cout << "No movie with the given ID was found." << std::endl;
			std::cout << "Retype the ID: ";
			getline(std::cin, temp);
			ID = atoi(temp.c_str());
		}
		else
			break;
	}
	std::cout << "Type the new trailer: ";
	std::string new_trailer;
	getline(std::cin, new_trailer);
	this->ctrl.update_trailer(ID, new_trailer);
	std::cout << "The trailer of the movie with the ID " << ID << " has been successfully modified!" << std::endl;
}

void UI::ShowAllMovies()
{
	// This method shows all the movies from the list of movies.
	DynamicVector vector = this->ctrl.get_repository().getMovies();
	Movie* movie = vector.getAllElems();
	if (movie == NULL)
		return;
	if (vector.getSize() == 0)
	{
		std::cout << "There are no movies in the database." << std::endl;
		return;
	}
	std::cout << "The movies from the database: " << std::endl << std::endl;
	for (int i = 0; i < vector.getSize(); i++)
	{
		Movie m = movie[i];
		std::cout << i + 1 << "." << "ID: " << m.get_id() << std::endl;
		std::cout << "  Title: " << m.get_title() << std::endl;
		std::cout << "  Genre: " << m.get_genre() << std::endl;
		std::cout << "  Apparition year: " << m.get_apparition_year() << std::endl;
		std::cout << "  Number of likes: " << m.get_number_of_likes() << std::endl;
		std::cout << "  Trailer: " << m.get_trailer() << std::endl;
		std::cout << std::endl;
	}
}

void UI::ShowWatchlist()
{
	// This method shows all the movies from the watchlist.
	DynamicVector vector = this->ctrl.get_watchlist_repo().getMovies();
	Movie* movie = vector.getAllElems();
	if (movie == NULL)
		return;
	if (vector.getSize() == 0)
	{
		std::cout << "There are no movies in the database." << std::endl;
		return;
	}
	std::cout << "The movies from the database: " << std::endl << std::endl;
	for (int i = 0; i < vector.getSize(); i++)
	{
		Movie m = movie[i];
		std::cout << i + 1 << "." << "ID: " << m.get_id() << std::endl;
		std::cout << "  Title: " << m.get_title() << std::endl;
		std::cout << "  Genre: " << m.get_genre() << std::endl;
		std::cout << "  Apparition year: " << m.get_apparition_year() << std::endl;
		std::cout << "  Number of likes: " << m.get_number_of_likes() << std::endl;
		std::cout << "  Trailer: " << m.get_trailer() << std::endl;
		std::cout << std::endl;
	}
}

void UI::ShowMoviesByGenre()
{
	// This method shows all the movies with a specific genre.
	std::cout << "Type the genre: ";
	std::string genre;
	getline(std::cin, genre);
	if (genre != "")
	{
		DynamicVector vector = this->ctrl.search_by_genre(genre);
		Movie* movie = vector.getAllElems();
		if (movie == NULL)
			return;
		if (vector.getSize() == 0)
		{
			std::cout << "No movie with the given genre was found." << std::endl;
			return;
		}
		std::cout << "The movies with the given genre: " << std::endl;
		std::cout << std::endl;
		for (int i = 0; i < vector.getSize(); i++)
		{
			Movie m = movie[i];
			std::cout << i + 1 << "." << "ID: " << m.get_id() << std::endl;
			std::cout << "  Title: " << m.get_title() << std::endl;
			std::cout << "  Genre: " << m.get_genre() << std::endl;
			std::cout << "  Apparition year: " << m.get_apparition_year() << std::endl;
			std::cout << "  Number of likes: " << m.get_number_of_likes() << std::endl;
			std::cout << "  Trailer: " << m.get_trailer() << std::endl;
			std::cout << std::endl;
		}
	}
	else
	{
		DynamicVector vector = this->ctrl.get_all_movies();
		Movie* movie = vector.getAllElems();
		Watchlist watchlist;
		if (movie == NULL)
			return;
		std::cout << "All the movies, but one by one: " << std::endl;
		std::cout << std::endl;
		for (int i = 0; i < vector.getSize(); i++)
		{
			Movie m = movie[i];
			int ID = m.get_id();
			std::string Title = m.get_title();
			std::string Genre = m.get_genre();
			int ApparitionYear = m.get_apparition_year();
			int NumberOfLikes = m.get_number_of_likes();
			std::string Trailer = m.get_trailer();
			std::cout << i + 1 << "." << "ID: " << ID << std::endl;
			std::cout << "  Title: " << Title << std::endl;
			std::cout << "  Genre: " << Genre << std::endl;
			std::cout << "  Apparition year: " << ApparitionYear << std::endl;
			std::cout << "  Number of likes: " << NumberOfLikes << std::endl;
			std::cout << "  Trailer: " << Trailer << std::endl;
			std::cout << std::endl;
			m.Play();
			std::cout << std::endl << "Do you like the trailer? Type Yes or No." << std::endl;
			std::string trailer_option;
			getline(std::cin, trailer_option);
			bool condition1 = true;
			while (condition1)
			{
				if (trailer_option == "Yes" || trailer_option == "yes")
				{
					std::cout << std::endl << "Do you want to add the movie to the watchlist? Type Yes or No." << std::endl;
					std::string watchlist_option;
					getline(std::cin, watchlist_option);
					bool condition2 = true;
					while (condition2)
					{
						if (watchlist_option == "Yes" || watchlist_option == "yes")
						{
							this->ctrl.add_movie_to_watchlist(ID, Title, Genre, ApparitionYear, NumberOfLikes, Trailer);
							std::cout << "Added to the watchlist." << std::endl;
							std::cout << "Press any key to continue." << std::endl;
							condition2 = false;
						}
						else if (watchlist_option == "No" || watchlist_option == "no")
						{
							std::cout << "The movie was not added to the watchlist." << std::endl;
							std::cout << "Press any key to continue." << std::endl;
							condition2 = false;
						}
						else
						{
							std::cout << "Invalid option." << std::endl;
							std::cout << "Retype the option: ";
							getline(std::cin, watchlist_option);
						}
					}
					condition1 = false;
				}
				else if (trailer_option == "No" || trailer_option == "no")
				{

					std::cout << "The movie was not added to the watchlist." << std::endl;
					std::cout << "Press any key to continue." << std::endl;
					condition1 = false;
				}
				else
				{
					std::cout << "Invalid option." << std::endl;
					std::cout << "Retype the option: ";
					getline(std::cin, trailer_option);
				}
			}
			getchar();
		}
	}
}

void UI::run()
{
	// This method runs the user interface.
	while (true)
	{
		UI::printMenu();
		int option;
		std::string temp;
		getline(std::cin, temp);
		option = atoi(temp.c_str());
		if (option == 0)
			break;

		if (option == 1)
		{
			while (true)
			{
				UI::printAdminMenu();
				int admin_option;
				std::string temp;
				getline(std::cin, temp);
				admin_option = atoi(temp.c_str());
				if (admin_option == 0)
					break;
				switch (admin_option)
				{
				case 1:
					this->AddMovie();
					break;
				case 2:
					this->DeleteMovie();
					break;
				case 3:
					this->UpdateTitle();
					break;
				case 4:
					this->UpdateGenre();
					break;
				case 5:
					this->UpdateNumberOfLikes();
					break;
				case 6:
					this->UpdateTrailer();
					break;
				case 7:
					this->ShowAllMovies();
					break;
				}
			}
		}

		if (option == 2)
		{
			while (true)
			{
				UI::printUserMenu();
				int user_option;
				std::string temp;
				getline(std::cin, temp);
				user_option = atoi(temp.c_str());
				if (user_option == 0)
					break;
				switch (user_option)
				{
				case 1:
					this->ShowMoviesByGenre();
					break;
				case 2:
					this->ShowAllMovies();
					break;
				case 3:
					this->ShowWatchlist();
					break;
				case 4:
					this->DeleteMovieFromWatchlist();
					break;
				}
			}
		}
	}
}