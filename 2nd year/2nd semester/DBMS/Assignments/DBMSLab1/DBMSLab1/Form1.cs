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

namespace DBMSLab1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            parentTableDgv.CellClick += new DataGridViewCellEventHandler(dataGridView1_CellClick);
            childTableDgv.CellClick += new DataGridViewCellEventHandler(childTableDgv_CellClick);

            idTextBox.Text = "ID";
            nameTextBox.Text = "Name";
            classTextBox.Text = "Class ID";
            profIdTextBox.Text = "Prof ID";
            guildIdTextBox.Text = "Guild ID";
            questIdTextBox.Text = "Quest ID";
        }

        public void BindData()
        {
            SqlDataAdapter da = new SqlDataAdapter("SELECT * FROM Guild", "Server = NECSOI\\SQLEXPRESS; Database = WoWCharacters2; Trusted_Connection = True");
            DataSet ds = new DataSet();
            da.Fill(ds, "Guild");
            parentTableDgv.DataSource = ds.Tables["Guild"].DefaultView;

            parentTableDgv.ReadOnly = false;
        }

        private void fillDgvButton_Click(object sender, EventArgs e)
        {
            BindData();
        }

        private void ShowPlayersForGuildCell()
        {
            // Last row is empty and the app will crash if not for this check
            if (!(parentTableDgv.CurrentRow.Index == parentTableDgv.RowCount - 1))
            {

                int id = int.Parse(parentTableDgv.Rows[parentTableDgv.CurrentRow.Index].Cells[0].Value.ToString());

                SqlDataAdapter da = new SqlDataAdapter("SELECT * FROM Player WHERE guild_id = " + id.ToString(), "Server = NECSOI\\SQLEXPRESS; Database = WoWCharacters2; Trusted_Connection = True");
                DataSet ds = new DataSet();
                da.Fill(ds, "Player");
                childTableDgv.DataSource = ds.Tables["Player"].DefaultView;
            }
        }

        private void dataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            ShowPlayersForGuildCell();
        }

        private void addPlayerButton_Click(object sender, EventArgs e)
        {
            var sqlQuery = "SELECT * FROM Player";
            SqlDataAdapter dataAdapter = new SqlDataAdapter(sqlQuery, "Server = NECSOI\\SQLEXPRESS; Database = WoWCharacters2; Trusted_Connection = True");
            DataSet dataSet = new DataSet();
            dataAdapter.Fill(dataSet, "Player");

            dataAdapter.TableMappings.Add("id", "id");
            dataAdapter.TableMappings.Add("name", "name");
            dataAdapter.TableMappings.Add("class", "class");
            dataAdapter.TableMappings.Add("prof_id", "prof_id");
            dataAdapter.TableMappings.Add("guild_id", "guild_id");
            dataAdapter.TableMappings.Add("quest_id", "quest_id");
            
            var newRow = dataSet.Tables["Player"].NewRow();
            newRow["id"] = int.Parse(idTextBox.Text);
            newRow["name"] = nameTextBox.Text;
            newRow["class"] = int.Parse(classTextBox.Text);
            newRow["prof_id"] = int.Parse(profIdTextBox.Text);
            newRow["guild_id"] = int.Parse(guildIdTextBox.Text);
            newRow["quest_id"] = int.Parse(questIdTextBox.Text);


            dataSet.Tables["Player"].Rows.Add(newRow);

            new SqlCommandBuilder(dataAdapter);
            dataAdapter.Update(dataSet, "Player");

            ShowPlayersForGuildCell();
        }

        private void childTableDgv_CellClick(object sender, DataGridViewCellEventArgs e)
        {
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
        }

        private void upatePlayerButton_Click(object sender, EventArgs e)
        {
            var sqlQuery = "SELECT * FROM Player";
            SqlDataAdapter dataAdapter = new SqlDataAdapter(sqlQuery, "Server = NECSOI\\SQLEXPRESS; Database = WoWCharacters2; Trusted_Connection = True");
            DataSet dataSet = new DataSet();
            dataAdapter.Fill(dataSet, "Player");

            //dataAdapter.TableMappings.Add("id", "id");
            //dataAdapter.TableMappings.Add("name", "name");
            //dataAdapter.TableMappings.Add("class", "class");
            //dataAdapter.TableMappings.Add("prof_id", "prof_id");
            //dataAdapter.TableMappings.Add("guild_id", "guild_id");
            //dataAdapter.TableMappings.Add("quest_id", "quest_id");

            DataTable dt = dataSet.Tables["Player"];
            //dt.Rows[childTableDgv.CurrentRow.Index]["id"] = idTextBox.Text;
            dt.Rows[childTableDgv.CurrentRow.Index]["name"] = nameTextBox.Text;
            dt.Rows[childTableDgv.CurrentRow.Index]["class"] = classTextBox.Text;
            dt.Rows[childTableDgv.CurrentRow.Index]["prof_id"] = profIdTextBox.Text;
            dt.Rows[childTableDgv.CurrentRow.Index]["guild_id"] = guildIdTextBox.Text;
            dt.Rows[childTableDgv.CurrentRow.Index]["quest_id"] = questIdTextBox.Text;

            /*
            string updateCommand = "UPDATE Player SET name = " + nameTextBox.Text +
                ", class = " + classTextBox.Text +
                ", prof_id = " + profIdTextBox.Text +
                ", guild_id = " + guildIdTextBox.Text +
                ", quest_id = " + questIdTextBox.Text +
                " WHERE id = " + idTextBox.Text;
            */

            new SqlCommandBuilder(dataAdapter);
            dataAdapter.Update(dataSet, "Player");
            ShowPlayersForGuildCell();
            //MessageBox.Show("Updated!");
        }

        private void deletePlayerButton_Click(object sender, EventArgs e)
        {
            var sqlQuery = "SELECT * FROM Player";
            SqlConnection conn = new SqlConnection("Server = NECSOI\\SQLEXPRESS; Database = WoWCharacters2; Trusted_Connection = True");
            SqlDataAdapter dataAdapter = new SqlDataAdapter(sqlQuery, conn);
            DataSet dataSet = new DataSet();
            dataAdapter.Fill(dataSet, "Player");
            
            string deleteCommand = "DELETE FROM Player WHERE id = " + idTextBox.Text;

            SqlDataAdapter updatePlayerDa = new SqlDataAdapter();
            try
            {
                conn.Open();
                SqlCommand cmd = new SqlCommand(deleteCommand, conn);
                updatePlayerDa.DeleteCommand = cmd;
                updatePlayerDa.DeleteCommand.ExecuteNonQuery();

                ShowPlayersForGuildCell();
                //MessageBox.Show("Deleted!");
            }
            catch (Exception ex)
            {
                conn.Close();
            }
        }
    }
}
