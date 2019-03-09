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

            idTextBox.Text = "ID";
            nameTextBox.Text = "Name";
            classTextBox.Text = "Class ID";
            profIdTextBox.Text = "Prof ID";
            guildIdTextBox.Text = "Guild ID";
            questIdTextBox.Text = "Quest ID";
        }

        public void BindData()
        {
            /*
            DataTable dt = new DataTable();
            dt.Columns.Add("id", typeof(int));
            dt.Columns.Add("name", typeof(string));
            dt.Columns.Add("class", typeof(int));
            dt.Columns.Add("prof_id", typeof(int));
            dt.Columns.Add("guild_id", typeof(int));
            dt.Columns.Add("quest_id", typeof(int));
            */

            SqlDataAdapter da = new SqlDataAdapter("SELECT * FROM Guild", "Server = NECSOI\\SQLEXPRESS; Database = WoWCharacters2; Trusted_Connection = True");
            DataSet ds = new DataSet();
            da.Fill(ds, "Guild");
            parentTableDgv.DataSource = ds.Tables["Guild"].DefaultView;

            parentTableDgv.ReadOnly = false;

            //parentTableDgv.DataSource = dt;
            //parentTableDgv.DataBind()
        }

        private void fillDgvButton_Click(object sender, EventArgs e)
        {
            BindData();
        }

        private void dataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
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
            dataAdapter.Update(dataSet);
        }
    }
}
