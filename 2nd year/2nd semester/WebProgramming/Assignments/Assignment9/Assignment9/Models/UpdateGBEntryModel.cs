using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.ComponentModel.DataAnnotations;

namespace Assignment9.Models
{
    public class UpdateGBEntryModel
    {
        [Required]
        [Display(Name = "Id")]
        [DataType(DataType.Text)]
        public string Id { get; set; }

        [Required]
        [Display(Name = "Email")]
        [DataType(DataType.Text)]
        public string Email { get; set; }

        [Required]
        [Display(Name = "Title")]
        [DataType(DataType.Text)]
        public string Title { get; set; }

        [Required]
        [Display(Name = "Comment")]
        [DataType(DataType.Text)]
        public string Comment { get; set; }
    }
}
