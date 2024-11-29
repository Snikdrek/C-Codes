#include <iostream>
#include <vector>

using namespace std;

class Movie {
    string title;
    string director;
    int year;

public:
    Movie(string title, string director, int year) {
        this->title = title;
        this->director = director;
        this->year = year;
    }

    string getTitle() {
        return title;
    }

    string getDirector() {
        return director;
    }

    int getYear() {
        return year;
    }
};

class MovieManager {
    vector<Movie> movies;

public:
    void addMovie(string title, string director, int year) {
        Movie movie(title, director, year);
        movies.push_back(movie);
    }

    void displayMovies() {
        for (const Movie& movie : movies) {
            cout << "Title: " << movie.getTitle() << endl;
            cout << "Director: " << movie.getDirector() << endl;
            cout << "Year: " << movie.getYear() << endl;
            cout << "------------------------" << endl;
        }
    }
};

int main() {
    MovieManager movieManager;

    // Add movies
    movieManager.addMovie("Movie 1", "Director 1", 2021);
    movieManager.addMovie("Movie 2", "Director 2", 2022);
    movieManager.addMovie("Movie 3", "Director 3", 2023);

    // Display movies
    movieManager.displayMovies();

    return 0;
}