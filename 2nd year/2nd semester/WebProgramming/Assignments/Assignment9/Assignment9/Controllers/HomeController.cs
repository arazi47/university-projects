using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Assignment9.Models;
using System.Data.Common;
using MySql.Data.MySqlClient;

namespace Assignment9.Controllers
{
    public class HomeController : Controller
    {
        public static string username, password;

        public HomeController() {}
        
        public IActionResult Index()
        {
            return View();
        }

        public IActionResult About()
        {
            ViewData["Message"] = "Your application description page.";

            return View();
        }

        public IActionResult Contact()
        {
            ViewData["Message"] = "Your contact page.";

            return View();
        }

        public IActionResult Privacy()
        {
            return View();
        }

        public IActionResult Login()
        {
            return View();
        }

        //
        // POST: /Home/Login
        [HttpPost]
        public async Task<ActionResult> Login(LoginViewModel model, string returnUrl)
        {
            if (!ModelState.IsValid)
            {
                return RedirectToPage("/~");
            }

            string connstring = string.Format("Server=localhost; database=weblab7; UID=root; password=root1234");
            var connection = new MySqlConnection(connstring);
            connection.Open();

            string query = "SELECT * FROM Administrator WHERE username='" + model.Username + "' AND password='" + model.Password + "'";
            var cmd = new MySqlCommand(query, connection);
            var reader = cmd.ExecuteReader();
            if (reader.Read())
            {
                HomeController.username = model.Username;
                HomeController.password = model.Password;
                return View();
            }

            connection.Close();

            // Go back to the index page (basically the login page)
            return LocalRedirect("~/");
        }

        [HttpPost]
        public async Task<ActionResult> SubmitGBEntry(SubmitGBEntryModel model, string returnUrl)
        {
            if (!ModelState.IsValid)
            {
                return Redirect("www.google.com");
                return LocalRedirect("/~");
            }

            string connstring = string.Format("Server=localhost; database=weblab7; UID=root; password=root1234");
            var connection = new MySqlConnection(connstring);
            connection.Open();
            
            string query = string.Format("INSERT INTO guestbook(author_email, title, description, posted_on) VALUES('{0}', '{1}', '{2}', '{3}')", HomeController.username, model.Title, model.Text, DateTime.Now.ToString("yyyy-MM-dd"));
            var cmd = new MySqlCommand(query, connection);
            cmd.ExecuteNonQuery();

            connection.Close();

            // Go back to the index page (basically the login page)
            // If we redirect to /Home/Login, the username won't be kept
            return LocalRedirect("~/");
        }

        [HttpPost]
        public async Task<ActionResult> Update(SubmitGBEntryModel model)
        {
            string connstring = string.Format("Server=localhost; database=weblab7; UID=root; password=root1234");
            var connection = new MySqlConnection(connstring);
            connection.Open();

            //model.Email = "ASDASD";
            //model.Title = "DSADAS";
            //model.Comment = "KMAKSDMAK";
            model.Id = "3";
            string query = "UPDATE guestbook SET author_email = '" + model.Email + "', title = '" + model.TitleUpd + "', description = '" + model.Comment + "' WHERE id = " + model.Id;
            var cmd = new MySqlCommand(query, connection);
            cmd.ExecuteNonQuery();

            connection.Close();

            return LocalRedirect("~/");
        }

        [HttpPost]
        public async Task<ActionResult> Delete(SubmitGBEntryModel model)
        {
            string connstring = string.Format("Server=localhost; database=weblab7; UID=root; password=root1234");
            var connection = new MySqlConnection(connstring);
            connection.Open();

            string query = "DELETE FROM guestbook WHERE id = " + model.Id;
            var cmd = new MySqlCommand(query, connection);
            cmd.ExecuteNonQuery();

            connection.Close();

            return LocalRedirect("~/");
        }

        [HttpPost]
        public async Task<ActionResult> ApplyFilter()
        {
            string connstring = string.Format("Server=localhost; database=weblab7; UID=root; password=root1234");
            var connection = new MySqlConnection(connstring);
            connection.Open();

            string query = "SELECT * FROM guestbook WHERE author_email='" + Request.Form["filterSelect"] + "'";
            var cmd = new MySqlCommand(query, connection);
            var reader = cmd.ExecuteReader();

            string tableHTML = "<table id=\"filteredgbentries-table\" border = \"1\"><tr><th>ID</th><th>Author's Email</th><th>Title</th><th>Description</th><th>Posted on</th></tr>";

            while (reader.Read())
            {
                int id = reader.GetInt32(0);
                string username = reader.GetString(1);
                string title = reader.GetString(2);
                string desc = reader.GetString(3);
                tableHTML += "<tr>";
                tableHTML += "<td>" + id + "</td>";
                tableHTML += "<td>" + username + "</td>";
                tableHTML += "<td>" + title + "</td>";
                tableHTML += "<td>" + desc + "</td>";
                // Date and time are split by space, we only need the date
                tableHTML += "<td>" + reader.GetDateTime(4).ToString().Split(' ')[0] + "</td>";
            }

            tableHTML += "</table>";


            connection.Close();
            return LocalRedirect("~/");
        }

        [ResponseCache(Duration = 0, Location = ResponseCacheLocation.None, NoStore = true)]
        public IActionResult Error()
        {
            return View(new ErrorViewModel { RequestId = Activity.Current?.Id ?? HttpContext.TraceIdentifier });
        }
    }
}
