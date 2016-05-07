class String
{
public:
    String(const char *str = NULL);
    String(const String &other);
    ~String(void);
    String & operate =(const String &other);

private:
    char *m_data;
};


String::~String(void)
{
    delete [] m_data;
}


String::String(const char *str)
{
    if (NULL == str)
    {
        m_data = new char[1];
        if (m_data != NULL)
        {
             *m_data = '\0';
        }
    }
    else
    {
        int len = strlen(str);
        m_data = new char[len];
        if (m_data != NULL)
        {
             strcpy(m_data, str);
        }
    }
}



String::String(const String &other)
{
    int len = strlen(other.m_data);
    m_data = new char[len + 1];
    strcpy(m_data, other.m_data);
}



String & String::operate =(const String &other)
{
    if (this == &other)
        return *this;

    delete [] m_data;

    int len = strlen(other.m_data);
    m_data = new char[len + 1];
    if (m_data != NULL)
    {
        strcpy(m_data, other.m_data);
    }

    return *this;
}
