#include <bits/stdc++.h>
using namespace std;


// Define a struct to hold the data for each row in the CSV file
struct RowData {
    double ne;
    double ni;
    double te;
    double ti;
    double se;
    double si;
    double fe;
    double fi;
    string type;
    string name;
    
};

// Define a function to split a string into tokens based on a delimiter
vector<string> splitString(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Define a function to read the CSV file and parse the data
void readData(const string& filename, vector<RowData>& data) {
    // Open the CSV file
    ifstream file(filename);

    // Read the CSV file line by line and parse the data
    string line;
    getline(file, line); // Skip the header line
    while (getline(file, line)) {
        vector<string> tokens = splitString(line, ',');
        RowData row;
        row.name = tokens[1];
        row.ne = stod(tokens[3]);
        row.ni = stod(tokens[4]);
        row.te = stod(tokens[5]);
        row.ti = stod(tokens[6]);
        row.se = stod(tokens[7]);
        row.si = stod(tokens[8]);
        row.fe = stod(tokens[9]);
        row.fi = stod(tokens[10]);
        row.type = tokens[11];// Convert MBTI type to a number (0-15)
        
        data.push_back(row);
    }
}

// Define a function to calculate the Euclidean distance between two vectors
double euclideanDistance(const vector<double>& v1, const vector<double>& v2) {
    double distance = 0;
    for (int i = 0; i < v1.size(); i++) {
        distance += pow(v1[i] - v2[i], 2);
    }
    return sqrt(distance);
}

// Define a function to find the k nearest neighbors to a given data point
vector<int> kNearestNeighbors(const vector<RowData>& data, const vector<double>& query, int k) {
    vector<pair<double, int>> distances;
    for (int i = 0; i < data.size(); i++) {
        double distance = euclideanDistance(query, { data[i].ne, data[i].ni, data[i].te, data[i].ti, data[i].se, data[i].si, data[i].fe, data[i].fi });
        distances.push_back({ distance, i });
    }
    sort(distances.begin(), distances.end());
    vector<int> neighbors;
    for (int i = 0; i < k; i++) {
        neighbors.push_back(distances[i].second);
    }
    return neighbors;
}

string findMBTI (vector<RowData>& data, int n) {
    int E = 0, I = 0, S = 0, N = 0, T = 0, F = 0, J = 0, P = 0;
    for (int i = 0; i < n; i++) {

        if (data[i].type[0] == 'E') {
            E++;
        } else {
            I++;
        }
        if (data[i].type[1] == 'S') {
            S++;
        } else {
            N++;
        }
        if (data[i].type[2] == 'T') {
            T++;
        } else {
            F++;
        }
        if (data[i].type[3] == 'J') {
            J++;
        } else {
            P++;
        }
    }
    string result = "";
    if (E > I) {
        result += "E";
    } else {
        result += "I";
    }
    if (S > N) {
        result += "S";
    } else {
        result += "N";
    }
    if (T > F) {
        result += "T";
    } else {
        result += "F";
    }
    if (J > P) {
        result += "J";
    } else {
        result += "P";
    }
    return result;
}
int main() {
    // Read the data from the CSV file
    vector<RowData> data;
    readData("data.csv", data);
    // Define a query data point
    vector<double> query = {33.6,32,34,31,31,37,36,29};
    //vector<double> query = {37,47.8,43,47,47,45,37,43};
    //vector<double> query = {21,25.6,29,30,28,29,28,30};
    // Find the 3 nearest neighbors to the query data point
    vector<int> neighbors = kNearestNeighbors(data, query, 3);

    // Output the neighbors and their corresponding Euclidean distances
    cout << "Nearest neighbors:" << endl;
    for (int i = 0; i < neighbors.size(); i++) {
        int index = neighbors[i];
        double distance = euclideanDistance(query, { data[index].ne, data[index].ni, data[index].te, data[index].ti, data[index].se, data[index].si, data[index].fe, data[index].fi });
        cout << "Name: " << data[index].name << ", Distance: " << distance << ", Type:" << data[index].type <<endl;
    }
    string MBTI = findMBTI(data, 3);
    cout << "Natchapon Ponlaem is " << MBTI << endl;

    return 0;
    

}
