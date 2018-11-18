class EnumExample 
{
  public static enum Server 
  {
    MARIADB ("mysql", "com.mysql.jdbc.Driver"), POSTGRESQL ("postgresql", "org.postgresql.Driver");
    
    private final String className;
    private final String driver;
    
    Server(String className, String driver)
    {
      this.className = className;
      this.driver = driver;
    }
    
    String className() { return this.className; }
    
    String driver() { return this.driver; }
  }

  public static void main(String[] args) 
  {
    Server hola = Server.MARIADB;
    System.out.println(hola);  
    // System.out.println((int)hola);  
    System.out.println(hola.className);  
  }
}