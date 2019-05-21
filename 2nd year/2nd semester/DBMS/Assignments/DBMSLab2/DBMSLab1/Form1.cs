using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Diagnostics;
using System.IO;

namespace DBMSLab1
{
    public partial class Form1 : Form
    {

        private string Scenario1Path;// = @"C:\Users\necso\source\repos\DBMSLab1\DBMSLab1\scenario1.txt";
        private List<string> queries;
        private int currentIndex = -1;

        public Form1()
        {
            OpenFileDialog fdlg = new OpenFileDialog();
            fdlg.Title = "Choose scenario file";
            fdlg.InitialDirectory = @"C:\Users\necso\source\repos\DBMSLab1\DBMSLab1";
            
            fdlg.ShowDialog();
            string fullPath = fdlg.FileName;
            Scenario1Path = fullPath;
            
            // BringToFront() doesn't work for me so I used this instead
            this.WindowState = FormWindowState.Minimized;
            this.Show();
            this.WindowState = FormWindowState.Normal;
            
            //string fileName = fdlg.SafeFileName;
            //string path = fullPath.Replace(fileName, "");
            //MessageBox.Show(fullPath);
            //fdlg.Title = "C# Corner Open File Dialog" ;
            //fdlg.InitialDirectory = @"c:\" ;
            //fdlg.Filter = "All files (*.*)|*.*|All files (*.*)|*.*" ;
            //fdlg.FilterIndex = 2 ;
            //fdlg.RestoreDirectory = true ;
            //if(fdlg.ShowDialog() == DialogResult.OK)
            //{
            //textBox1.Text = fdlg.FileName ;
            //}

            InitializeComponent();
            //parentTableDgv.CellClick += new DataGridViewCellEventHandler(dataGridView1_CellClick);
            //childTableDgv.CellClick += new DataGridViewCellEventHandler(childTableDgv_CellClick);

            //idTextBox.Text = "ID";
            //nameTextBox.Text = "Name";
            //classTextBox.Text = "Class ID";
            //profIdTextBox.Text = "Prof ID";
            //guildIdTextBox.Text = "Guild ID";
            //questIdTextBox.Text = "Quest ID";

            queries = new List<string>();
            ExecuteScenario(Scenario1Path);
        }

        public string GetCmdNameFromQuery(string query)
        {
            if (query.Length == 0)
                return "Unknown query";
            
            return query.Split(' ')[0];
        }
        
        public void ExecuteScenario(string FilePath)
        {
            string cmdText;

            // Read the file and display it line by line.  
            System.IO.StreamReader file = new System.IO.StreamReader(FilePath);
            while ((cmdText = file.ReadLine()) != null)
            {
                queries.Add(cmdText);
            }
            
            NextCommandTextBox.Multiline = true;
            NextCommandTextBox.Text = queries[0];
            NextCommandTextBox.Height = 100;
            NextCommandTextBox.ReadOnly = true;

            file.Close();
        }

        public void BindData()
        {
            SqlDataAdapter da = new SqlDataAdapter("SELECT * FROM Guild", "Server = NECSOI\\SQLEXPRESS; Database = WoWCharacters2; Trusted_Connection = True");
            DataSet ds = new DataSet();
            da.Fill(ds, "Guild");
            //parentTableDgv.DataSource = ds.Tables["Guild"].DefaultView;
            //parentTableDgv.ReadOnly = false;
        }

        public void ExecSelectCommand(string query)
        {
            string tableName = query.Split(' ').Last().Split(';')[0]; // last split is if we have a ;
            SqlDataAdapter da = new SqlDataAdapter(query, "Server = NECSOI\\SQLEXPRESS; Database = WoWCharacters2; Trusted_Connection = True");
            DataSet ds = new DataSet();
            da.Fill(ds, tableName);
            dgv.DataSource = ds.Tables[tableName].DefaultView;
            dgv.ReadOnly = true;
        }
        
        private void fillDgvButton_Click(object sender, EventArgs e)
        {
            BindData();
        }

        private void ShowPlayersForGuildCell()
        {
            /*
            // Last row is empty and the app will crash if not for this check
            if (!(parentTableDgv.CurrentRow.Index == parentTableDgv.RowCount - 1))
            {

                int id = int.Parse(parentTableDgv.Rows[parentTableDgv.CurrentRow.Index].Cells[0].Value.ToString());

                SqlDataAdapter da = new SqlDataAdapter("SELECT * FROM Player WHERE guild_id = " + id.ToString(), "Server = NECSOI\\SQLEXPRESS; Database = WoWCharacters2; Trusted_Connection = True");
                DataSet ds = new DataSet();
                da.Fill(ds, "Player");
                childTableDgv.DataSource = ds.Tables["Player"].DefaultView;
            }
            */
        }

        private void ExecInsertCommand(string query)
        {
            using (SqlConnection conn = new SqlConnection("Server = NECSOI\\SQLEXPRESS; Database = WoWCharacters2; Trusted_Connection = True"))
            {
                using (SqlCommand cmd = new SqlCommand(query, conn))
                {
                    cmd.CommandType = CommandType.Text;
                    //cmd.Parameters.AddWithValue("@id", 123);
                    cmd.Parameters.AddWithValue("@name", "testaddname");
                    cmd.Parameters.AddWithValue("@class", 1);
                    cmd.Parameters.AddWithValue("@prof_id", 1);
                    cmd.Parameters.AddWithValue("@guild_id", 1);
                    cmd.Parameters.AddWithValue("@quest_id", 1);
                    conn.Open();
                    cmd.ExecuteNonQuery();
                    conn.Close();
                    //ShowPlayersForGuildCell();
                }
            }
        }

        private void childTableDgv_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            /*
            // Last row is empty and the app will crash if not for this check
            if (!(childTableDgv.CurrentRow.Index == childTableDgv.RowCount - 1))
            {
                int id = int.Parse(childTableDgv.Rows[childTableDgv.CurrentRow.Index].Cells[0].Value.ToString());
                string name = childTableDgv.Rows[childTableDgv.CurrentRow.Index].Cells[1].Value.ToString();
                int classId = int.Parse(childTableDgv.Rows[childTableDgv.CurrentRow.Index].Cells[2].Value.ToString());
                int profId = int.Parse(childTableDgv.Rows[childTableDgv.CurrentRow.Index].Cells[3].Value.ToString());
                int guildId = int.Parse(childTableDgv.Rows[childTableDgv.CurrentRow.Index].Cells[4].Value.ToString());
                int questId = int.Parse(childTableDgv.Rows[childTableDgv.CurrentRow.Index].Cells[5].Value.ToString());

                idTextBox.Text = id.ToString();
                nameTextBox.Text = name;
                classTextBox.Text = classId.ToString();
                profIdTextBox.Text = profId.ToString();
                guildIdTextBox.Text = guildId.ToString();
                questIdTextBox.Text = questId.ToString();
            }
            */
        }

        private void addPlayerButton_Click(object sender, EventArgs e)
        {
            string insertCommand = "INSERT INTO PLAYER(name, class, prof_id, guild_id, quest_id) VALUES (@name, @class, @prof_id, @guild_id, @quest_id)";
            ExecInsertCommand(insertCommand);
            ShowPlayersForGuildCell();
        }

        private void upatePlayerButton_Click(object sender, EventArgs e)
        {
            string updateCommand = "UPDATE Player SET name = @name, class = @class, prof_id = @prof_id, guild_id = @guild_id WHERE id = @id";
            ExecUpdateCommand(updateCommand);
            ShowPlayersForGuildCell();
        }

        private void deletePlayerButton_Click(object sender, EventArgs e)
        {
            string deleteCommand = @"DELETE FROM Player WHERE id = @id";
            ExecDeleteCommand(deleteCommand);
            ShowPlayersForGuildCell();
        }

        private void ExecUpdateCommand(string query)
        {
            using (SqlConnection conn = new SqlConnection("Server = NECSOI\\SQLEXPRESS; Database = WoWCharacters2; Trusted_Connection = True"))
            {
                using (SqlCommand cmd = new SqlCommand(query, conn))
                {
                    cmd.CommandType = CommandType.Text;
                    //cmd.Parameters.AddWithValue("@name", nameTextBox.Text);
                    //cmd.Parameters.AddWithValue("@class", classTextBox.Text);
                    //cmd.Parameters.AddWithValue("@prof_id", profIdTextBox.Text);
                    //cmd.Parameters.AddWithValue("@guild_id", guildIdTextBox.Text);
                    //cmd.Parameters.AddWithValue("@quest_id", questIdTextBox.Text);
                    //cmd.Parameters.AddWithValue("@id", idTextBox.Text);
                    conn.Open();
                    cmd.ExecuteNonQuery();
                    conn.Close();
                    //ShowPlayersForGuildCell();
                }
            }
        }

        private void ExecDeleteCommand(string query)
        {
            var sqlQuery = "SELECT * FROM Player";
            SqlConnection conn = new SqlConnection("Server = NECSOI\\SQLEXPRESS; Database = WoWCharacters2; Trusted_Connection = True");
            SqlDataAdapter dataAdapter = new SqlDataAdapter(sqlQuery, conn);
            DataSet dataSet = new DataSet();
            dataAdapter.Fill(dataSet, "Player");

            SqlDataAdapter updatePlayerDa = new SqlDataAdapter();
            try
            {
                conn.Open();
                SqlCommand cmd = new SqlCommand(query, conn);
                updatePlayerDa.DeleteCommand = cmd;
                updatePlayerDa.DeleteCommand.ExecuteNonQuery();

                //ShowPlayersForGuildCell();
                //MessageBox.Show("Deleted!");
            }
            catch (Exception ex)
            {
                conn.Close();
            }
        }

        // Execute next query button clicked
        private void button1_Click(object sender, EventArgs e)
        {
            currentIndex += 1;
            if (currentIndex == queries.ToArray().Length)
            {
                MessageBox.Show("No more queries to execute");
                return;
            }

            string query = queries[currentIndex];
            string cmdName = GetCmdNameFromQuery(query);

            // TODO: update dgv (datagridview) after each command
            // TODO: implement SELECT operator
            switch (cmdName.ToUpper())
            {
                case "SELECT":
                    ExecSelectCommand(query);
                    break;
                case "INSERT":
                    ExecInsertCommand(query);
                    break;
                case "UPDATE":
                    ExecUpdateCommand(query);
                    break;
                case "DELETE":
                    ExecDeleteCommand(query);
                    break;
                default:
                    MessageBox.Show("Unknown SQL query: \"" + query + "\"");
                    break;
            }

            if (currentIndex + 1 < queries.ToArray().Length)
            {
                query = queries[currentIndex + 1];
                cmdName = GetCmdNameFromQuery(query);
                //MessageBox.Show(cmdName);
                NextCommandTextBox.Multiline = true;
                NextCommandTextBox.Text = query;
                NextCommandTextBox.Height = 100;
                NextCommandTextBox.ReadOnly = true;
            }
            else
            {
                NextCommandTextBox.Multiline = true;
                NextCommandTextBox.Text = "No more queries to run.";
                NextCommandTextBox.Height = 100;
                NextCommandTextBox.ReadOnly = true;
            }
        }
    }
}
