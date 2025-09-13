<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<%@ page import="java.sql.* , java.sql.DriverManager, java.util.*"  %>

<% 
         Class.forName("com.mysql.cj.jdbc.Driver");
         Connection conn = DriverManager.getConnection("jdbc:mysql://localhost/demo", "root", "");
        Statement st=conn.createStatement();
    
        String id = request.getParameter("t1");
        String name = request.getParameter("t2");
        //out.print(id+name);
        st.executeUpdate("insert into emp(id,name) values("+id+",'"+name+"');");
        //out.println("Data is successfully inserted!");
        out.println("<script> window.alert('Data is successfully inserted!'); window.location.href('index.html')</script>");
        
 %>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Insert title here</title>
</head>
<body>
</body>
</html>