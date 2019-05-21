using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DBMS_Lab3_Deadlock
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void Deadlock2()
        {
            Deadlock("deadlock1");
        }

        private void Deadlock1()
        {
            Deadlock("deadlock2");
        }

        void Deadlock(String deadlock)
        {
            SqlConnection connection = new SqlConnection("Server = NECSOI\\SQLEXPRESS; Database = deadlocktestdb; Trusted_Connection = True");
            MessageBox.Show(deadlock + " started!");
            SqlCommand command = new SqlCommand(deadlock, connection);
            command.CommandType = CommandType.StoredProcedure;
            connection.Open();
            int rows_affected = 0;
            try
            {
                rows_affected = command.ExecuteNonQuery();
            }
            catch (Exception ex)
            {
                MessageBox.Show(deadlock + " failed!");
                int tries = 1;
                while (rows_affected < 2 && tries > 0)
                {
                    MessageBox.Show(deadlock + " failed! rows affected: " + rows_affected + " tries: " + tries);
                    try
                    {
                        rows_affected = command.ExecuteNonQuery();
                        MessageBox.Show(deadlock + " tries: " + (1 - tries + 1));
                    }
                    catch (Exception exe)
                    {
                        MessageBox.Show(deadlock + " failed!");
                    }
                }
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            ThreadStart deadlock1 = new ThreadStart(Deadlock1);
            ThreadStart deadlock2 = new ThreadStart(Deadlock2);

            Thread d1 = new Thread(deadlock1);
            Thread d2 = new Thread(deadlock2);

            d1.Start();
            d2.Start();
        }
    }
}
