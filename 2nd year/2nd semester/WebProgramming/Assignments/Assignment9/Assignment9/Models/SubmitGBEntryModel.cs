using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

using System.ComponentModel.DataAnnotations;

namespace Assignment9.Models
{
    public class SubmitGBEntryModel
    {
        [Required]
        [Display(Name = "Title")]
        [DataType(DataType.Text)]
        public string Title { get; set; }

        [Required]
        [Display(Name = "Text")]
        [DataType(DataType.Text)]
        public string Text { get; set; }

        [Display(Name = "Id")]
        [DataType(DataType.Text)]
        public string Id { get; set; }

        [Display(Name = "Email")]
        [DataType(DataType.Text)]
        public string Email { get; set; }

        [Display(Name = "TitleUpd")]
        [DataType(DataType.Text)]
        public string TitleUpd { get; set; }

        [Display(Name = "Comment")]
        [DataType(DataType.Text)]
        public string Comment { get; set; }
    }
}
