vector<string> subString(string &str)
{
	vector<string> v;
    // First loop for starting index
    for (int i = 0; i < str.length(); i++) {
        string subStr;
        // Second loop is generating sub-string
        for (int j = i; j < str.length(); j++) {
            	subStr += str[j];
				v.push_back(subStr);
            
        }
    }
	
	return v;
}